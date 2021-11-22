
typedef struct CameraModule{
    Texture2D t;
    Vector2 pos;
    bool on;
    
}CameraModule;
typedef struct Cms{
    Texture2D cm1;
    Rectangle cm1Pos;
    Texture2D cm2;
    Rectangle cm2Pos;
    Texture2D cm3;
    Rectangle cm3Pos;
    Texture2D cm4;
    Rectangle cm4Pos;
    Texture2D cm5;
    Rectangle cm5Pos;
    Texture2D cm6;
    Rectangle cm6Pos;
    Texture2D cm7;
    Rectangle cm7Pos;
    Texture2D cm8;
    Rectangle cm8Pos;
    Texture2D cm9;
    Rectangle cm9Pos;
    Texture2D cm10;
    Rectangle cm10Pos;
}Cms;
typedef struct CameraLocations
{
    Texture2D cml1;
    bool textureChange;
    Rectangle cml1Pos;
    bool cml1on;
    Texture2D cml2;
    bool textureChange2;
    Rectangle cml2Pos;
    bool cml2on;
}CameraLocations;
typedef enum Gamescreen{LOGO,TITLE,POWERUPS,N1,N2,N3,N4,N5,RUNNING,NC,DEAD}Gamescreen;
