/*
 * NOTE: the project is gone for now might come back l8r but i have doubts about that,soooooo yeh,S its a kids game in the end
 * 
 * TODO:
 * addEnemies[];  
 * --EDM 1[];
 * --EDM 2[];
 * --EDM 3[];
 * --EDM 4[];
 * addCameraLocations[1/10];
 * 
 * addCloset[];
 * 
 * addFindingMechanicInTheCloset[];
 * 
 * addPowerUps[];
 * 
 * 
 * 
 * BetterTitleAndLogo[];
 * betterTexture[];
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * */















#include "raylib.h"
#include "cms.h"
#include <stdio.h>

#define SCREENWIDTH 1000
#define SCREENHEIGHT 600

//put initilizations of variables here not in functions!
//local variables
static Gamescreen currentscreen;
static int frameCounter;
static Vector2 mousePos;
 static int framerate;
 static bool ON;
 static bool animOn;
//N variables
static Texture2D backGround;
static Rectangle cameraBlock;

//Scenes and Gameplay
//0-LOGO

//1-Titles
void Title();
//2-PowerUps

//3-N1
void Night1(Camera2D *camera,Rectangle *cameraButton,CameraModule *cameraModel,Cms *cameraPlaces,CameraLocations *cameraLoc,int *Monster);
//main loop
int main(void)
{
    
    //init
    InitWindow(SCREENWIDTH,SCREENHEIGHT,"fnad-test mode");
    //for cms
    int w=87;
    int h=69;
    //for cameraLocations
    int w2=850;
    int h2=516;
    currentscreen=LOGO;
    backGround=LoadTexture("res/t1.png");
    CameraModule cameraModel={LoadTexture("res/camera.png"),(Vector2){0,600},false};
    Cms cameraPlaces={LoadTexture("res/cm/cm1.png"),{-100,0,w,h},LoadTexture("res/cm/cm2.png"),{-100,0,w,h}
        ,LoadTexture("res/cm/cm3.png"),{-100,0,w,h},LoadTexture("res/cm/cm4.png"),{-100,0,w,h}
        ,LoadTexture("res/cm/cm5.png"),{-100,0,w,h},LoadTexture("res/cm/cm6.png"),{-100,0,w,h}
        ,LoadTexture("res/cm/cm7.png"),{-100,0,w,h},LoadTexture("res/cm/cm8.png"),{-100,0,w,h}
        ,LoadTexture("res/cm/cm9.png"),{-100,0,w,h},LoadTexture("res/cm/cm10.png")};
    CameraLocations cameraLoc={LoadTexture("res/cameraPlaces/cm1Place.png"),true,{-100,0,w2,h2},false,LoadTexture("res/cameraPlaces/cm2Place.png"),true,{-100,0,w2,h2},false};
   //Enemies location data
   int Monster=0; 
   //debugging purpose
    Rectangle cameraButton={350,546,340,60};
    mousePos=GetMousePosition();
    
    framerate=0;
    Camera2D camera={0};

        camera.offset=(Vector2){0,0};
        camera.rotation=0.0f;
        camera.zoom=1.0f;

    cameraBlock.x=SCREENWIDTH/2; 
    cameraBlock.y=SCREENHEIGHT/2;
    cameraBlock.width=10;
    cameraBlock.height=10;
    
    

    
    //frame stuff
     int framecount=0;
     SetTargetFPS(60);
    
    //game loop
    while(!WindowShouldClose())
    {
        //updates
     
        switch(currentscreen)
        {
            case LOGO:
            {
                BeginDrawing();
                ClearBackground(BLACK);
                DrawText("Logo!",5,5,5,WHITE);
                EndDrawing(); 
                framecount++;
                  if(framecount>60)
                    {
                        currentscreen=TITLE;
                       framecount=0;
                    }
        }break;
            case TITLE:{
            Title();
            }break;
            case N1:{
            Night1(&camera,&cameraButton,&cameraModel,&cameraPlaces,&cameraLoc,&Monster);
            }break;
            case N2:{
            
            }break;
            case N3:{
            
            }break;
            case N4:{
            
            }break;
            case N5:{
            
            }break;
            case NC:{
            
            }break;
            case DEAD:{
            
            }break;
            
        }
        
        
    }
    UnloadTexture(backGround);
    UnloadTexture(cameraModel.t);
    UnloadTexture(cameraPlaces.cm1);
    UnloadTexture(cameraPlaces.cm2);
    UnloadTexture(cameraPlaces.cm3);
    UnloadTexture(cameraPlaces.cm4);
    UnloadTexture(cameraPlaces.cm5);
    UnloadTexture(cameraPlaces.cm6);
    UnloadTexture(cameraPlaces.cm7);
    UnloadTexture(cameraPlaces.cm8);
    UnloadTexture(cameraPlaces.cm9);
    UnloadTexture(cameraPlaces.cm10);
    UnloadTexture(cameraLoc.cml1);
    UnloadTexture(cameraLoc.cml2);
    CloseWindow();
    
    
}


//TITLE
void Title()
{
    
  if(IsKeyPressed(KEY_ENTER)) currentscreen=N1;
    
    //renderer
    BeginDrawing();
    ClearBackground(BLACK);
    DrawText("Title Screen!",2,4,20,WHITE);
    DrawText("Press Enter To Start!",100,SCREENHEIGHT/2,50,WHITE);
    EndDrawing();
    //end of renderer
}
//END OF TITLE
//Nights
void Night1(Camera2D *camera,Rectangle *cameraButton,CameraModule *cameraModel,Cms *cameraPlaces,CameraLocations *cameraLoc,int *Monster)
{
   framerate++;
      printf("\ny: %f\n",mousePos.y);
         printf("\nx: %f\n",mousePos.x);
            mousePos=GetMousePosition();
            

    if(cameraModel->on==false)
    {
     if(GetMouseX()>600&&camera->offset.x>=-290) camera->offset.x-=3.0f;
     if(GetMouseX()<500&&camera->offset.x<=270) camera->offset.x+=3.0f;
    }
    // printf("%f \n",camera->offset.x);
    
    //camera turn on and off system
    if(CheckCollisionPointRec(mousePos,*cameraButton)&& !cameraModel->on&&ON==false) 
    {
       cameraModel->on=true;
       animOn=true;
       ON=true;
       
    }else if(CheckCollisionPointRec(mousePos,*cameraButton)&& cameraModel->on&&ON==false)
    {
        cameraModel->on=false;
         animOn=false;
       
        ON=true;
    }else if (!CheckCollisionPointRec(mousePos,*cameraButton))
    {
        ON=false;
    }
    //animation for camera values
    if(animOn&&cameraModel->pos.y>0)
    {
        cameraModel->pos.y-=50;
    }else if(!animOn&&cameraModel->pos.y<600)
    {
                cameraModel->pos.y+=50;
    }
         
    if(cameraModel->pos.y==0)
    {
        cameraPlaces->cm1Pos.x=202;
        cameraPlaces->cm1Pos.y=45;
        cameraPlaces->cm2Pos.x=202;
        cameraPlaces->cm2Pos.y=490;
        
        
    }else
    {
        cameraPlaces->cm1Pos.x=-100;
        cameraPlaces->cm1Pos.y=0;
cameraPlaces->cm2Pos.x=-100;
        cameraPlaces->cm2Pos.y=0;
    }
    //CameraLocations
    if(CheckCollisionPointRec(mousePos,cameraPlaces->cm1Pos)&&IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
        printf("\nWorked\n");
        cameraLoc->cml1on=true;
 cameraLoc->cml2on=false;
        cameraLoc->cml1Pos.x=49;
        cameraLoc->cml1Pos.y=43;
         
    }
if(CheckCollisionPointRec(mousePos,cameraPlaces->cm2Pos)&&IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
{
cameraLoc->cml1on=false;
 cameraLoc->cml2on=true;
        cameraLoc->cml2Pos.x=49;
        cameraLoc->cml2Pos.y=43;
  }  //Enemis location data updating
    if(*Monster!=4&&framerate>260)
    {
        *Monster+=1;
        framerate=0;
    }
    //CameraLocations but with Enemies
    switch(*Monster)
    {
        case 1:
        {
            if(cameraLoc->textureChange)
            {
            cameraLoc->cml1=LoadTexture("res/cameraPlaces/cm1Place(phase2).png");
            cameraLoc->textureChange=false;
            }
        }break;
        case 2:
        {
        if(!cameraLoc->textureChange)
            {
             cameraLoc->cml1=LoadTexture("res/cameraPlaces/cm1Place.png");
             cameraLoc->textureChange=true;
             cameraLoc->cml2=LoadTexture("res/cameraPlaces/cm2Place(phase2).png");
             cameraLoc->textureChange2=false;
            }
        }break;
        case 3:
        {
             if(!cameraLoc->textureChange2)
            {
             cameraLoc->cml2=LoadTexture("res/cameraPlaces/cm2Place.png");
             cameraLoc->textureChange2=true;
            }
            if(IsKeyPressed(KEY_E))
            { 
            
                *Monster=GetRandomValue(0,2);
                if(*Monster==1) cameraLoc->textureChange=true;
                if(*Monster==2)cameraLoc->textureChange=false;
            }
        }break;
        case 4:
        {
          currentscreen=TITLE;  //Game Over Screen
          *Monster=0;
        }break;
    }
    
   //Defeat Enemies logic
   if(IsKeyPressed(KEY_A)&&*Monster!=0)*Monster-=1; 
   
   
   
   printf("\n%d\n",*Monster);
    
    
    
    //render
    BeginDrawing();
    ClearBackground(BLACK);
     
    //camera
    BeginMode2D(*camera);
  DrawTexture(backGround,-310,0,WHITE);
  if(*Monster==3)DrawRectangle(-50,366,40,40,RED);
    EndMode2D();
    if(cameraModel->pos.y!=600)DrawTexture(cameraModel->t,cameraModel->pos.x,cameraModel->pos.y,WHITE);
    if(cameraModel->pos.y==0)
    {
     //locations
    if(cameraLoc->cml1on)DrawTexture(cameraLoc->cml1,cameraLoc->cml1Pos.x,cameraLoc->cml1Pos.y,WHITE);
    if(cameraLoc->cml2on)DrawTexture(cameraLoc->cml2,cameraLoc->cml2Pos.x,cameraLoc->cml2Pos.y,WHITE);
    
    
    //buttons
     DrawTexture(cameraPlaces->cm1,cameraPlaces->cm1Pos.x,cameraPlaces->cm1Pos.y,WHITE);
    DrawTexture(cameraPlaces->cm2,cameraPlaces->cm2Pos.x,cameraPlaces->cm2Pos.y,WHITE);
    }
    //cameraLocations
    
    
    
    DrawRectangle(cameraBlock.x,cameraBlock.y,cameraBlock.width,cameraBlock.height,RED);
   DrawRectangle(cameraButton->x,cameraButton->y,cameraButton->width,cameraButton->height,BLUE);
   
          
          
      
    EndDrawing();
    
}





