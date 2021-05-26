/*
    The definition of the data can be seen in DVL Integrator's Guide.
    Official website: https://www.nortekgroup.com/
*/

/* Header part of the output data packet */
struct Header_t
{
    unsigned char sync;
    unsigned char hdrSize;
    unsigned char ID;
    unsigned char family;
    unsigned short dataSize;
    unsigned short dataChecksum;
    unsigned short hdrChecksum;
};

/* DF3 Velocity Data Record Struct Definition */
struct t_DataSetDescription4Bit
{
    unsigned short beamData1 : 4;
    unsigned short beamData2 : 4;
    unsigned short beamData3 : 4;
    unsigned short beamData4 : 4;
};

struct t_status
{
    unsigned long _empty1         : 21;
    unsigned long prevWakeUpState : 1;
    unsigned long autoOrient      : 3;
    unsigned long orientation     : 3;
    unsigned long wakeupstate     : 4;
};

struct t_status0
{
    unsigned short procIdle3  : 1;
    unsigned short procIdle6  : 1;
    unsigned short procIdle12 : 1;
    unsigned short _empty1    : 12;
    unsigned short stat0inUse : 1;
};

struct OutputData3_t
{
    unsigned char version; // 3
    unsigned char offsetOfData; // offsetof(BurstData3_t, data)
    struct headconfig
    {
        unsigned short pressure        : 1; // 0
        unsigned short temp            : 1; // 1
        unsigned short compass         : 1; // 2
        unsigned short tilt            : 1; // 3
        unsigned short _empty          : 1; // 4
        unsigned short velIncluded     : 1; // 5
        unsigned short ampIncluded     : 1; // 6
        unsigned short corrIncluded    : 1; // 7
        unsigned short altiIncluded    : 1; // 8
        unsigned short altiRawIncluded : 1; // 9
        unsigned short ASTIncluded     : 1; // 10
        unsigned short echoIncluded    : 1; // 11
        unsigned short ahrsIncluded    : 1; // 12
        unsigned short PGoodIncluded   : 1; // 13
        unsigned short stdDevIncluded  : 1; // 14
        unsigned short _unused         : 1; // 15
    };
    unsigned int serialNumber;
    unsigned char year;
    unsigned char month;
    unsigned char day;
    unsigned char hour;
    unsigned char minute;
    unsigned char seconds;
    unsigned short microSeconds100;
    unsigned short soundSpeed; // resolution: 0.1 m/s
    short temperature;         // resolution: 0.01 degree Celsius
    unsigned int pressure;
    unsigned short heading;
    short pitch;
    short roll;
    struct BCC
    {
        unsigned short NC : 10;
        unsigned short CS : 2;
        unsigned short NB : 4;
    };
    unsigned short cellSize;
    unsigned short blanking;
    unsigned char nominalCorrelation;
    unsigned char pressTemp;
    unsigned short battery;
    short magnHxHyHz[3]; ///< Magnetometer Min data
    short accl3D[3];     ///< Accelrometer Data
    unsigned short ambiguityVelocity;
    t_DataSetDescription4Bit DataSetDescription4bit;
    unsigned short transmitEnergy;
    char velocityScaling;
    char powerlevel;
    short magnTemperature;
    short rtcTemperature;
    unsigned short error;
    t_status0 status0; /* Unsigned short */
    t_status status; /* Unsigned long */
    unsigned int ensembleCounter;
};


/* DF21/22 Bottom Track/Water Track Record Struct Definition */
struct t_DVLstatus
{
    unsigned long beam1VelValid  : 1;
    unsigned long beam2VelValid  : 1;
    unsigned long beam3VelValid  : 1;
    unsigned long beam4VelValid  : 1;
    unsigned long beam1DistValid : 1;
    unsigned long beam2DistValid : 1;
    unsigned long beam3DistValid : 1;
    unsigned long beam4DistValid : 1;
    unsigned long beam1FOMValid  : 1;
    unsigned long beam2FOMValid  : 1;
    unsigned long beam3FOMValid  : 1;
    unsigned long beam4FOMValid  : 1;
    unsigned long xVelValid      : 1;
    unsigned long yVelValid      : 1;
    unsigned long z1VelValid     : 1;
    unsigned long z2VelValid     : 1;
    unsigned long xFOMValid      : 1;
    unsigned long yFOMValid      : 1;
    unsigned long z1FOMValid     : 1;
    unsigned long z2FOMValid     : 1;
    unsigned long procIdle3      : 1;
    unsigned long procIdle6      : 1;
    unsigned long procIdle12     : 1;
    unsigned long _empty1        : 5;
    unsigned long wakeupstate    : 4;
};

struct DVLformat21_t
{
    unsigned char version;
    unsigned char offsetOfData;
    unsigned int serialNumber;
    unsigned char year;
    unsigned char month;
    unsigned char day;
    unsigned char hour;
    unsigned char minute;
    unsigned char seconds;
    unsigned short microSeconds100;
    unsigned short nBeams;
    unsigned int error;
    t_DVLstatus status;
    float soundSpeed;
    float temperature;
    float pressure;

    /* Beam data */
    float velBeam[4];        ///< Velocities for each beam. [m/s]
    float distBeam[4];       ///< Distances for each beam. [m ]
    float fomBeam[4];        ///< FOM for each beam. [m/s]
    float timeDiff1Beam[4];  ///< DT1 for each beam. [s ]
    float timeDiff2Beam[4];  ///< DT2 for each beam. [s ]
    float timeVelEstBeam[4]; ///< Duration of velocity estimate for each beam.

    /* XYZ data */
    float velX;
    float velY;
    float velZ1;
    float velZ2;
    float fomX;
    float fomY;
    float fomZ1;
    float fomZ2;
    float timeDiff1X;
    float timeDiff1Y;
    float timeDiff1Z1;
    float timeDiff1Z2;
    float timeDiff2X;
    float timeDiff2Y;
    float timeDiff2Z1;
    float timeDiff2Z2;
    float timeVelEstX;
    float timeVelEstY;
    float timeVelEstZ1;
    float timeVelEstZ2;
};




// #include <iostream>
// using namespace std;
// int main(){
//     //DVLformat21_t a;
//     //short a;
//     OutputData3_t a;
//     cout << sizeof(a) << endl;
// }

