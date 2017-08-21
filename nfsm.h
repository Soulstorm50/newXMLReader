#ifndef NFSM_H
#define NFSM_H

#include <ctime>
#include <QString>
#include <QByteArray>
#include <QDataStream>

namespace Nfsm
{

//-------------------------- xml patch -----------------------------------------

    const QString xmlCarTypes = "D:\\111\\odstudents\\src\\Backend\\xml\\cartypes.xml";
    const QString xmlScenario = "D:\\111\\odstudents\\src\\Backend\\xml\\test2.xml";

//-------------------------- car types  ----------------------------------------
    const qint32 LEFT_HAND_CAR_TYPE = 300;
    const qint32 RIGHT_HAND_CAR_TYPE = 301;
    const qint32 TRACK_CAR_TYPE = 302;

//---- oil levels --------------------------------------------------------------
    const qint32 OIL_MIN_LEVEL = 0;
    const qint32 OIL_MIDDLE_LEVEL = 1;
    const qint32 OIL_MAX_LEVEL = 2;
//------------------------------------------------------------------------------

    const qint32 MAX_SPEED = 110;
    const double DEFAULT_FUEL_CHANGE_RATIO = 0.999;
    const double ACCELERATION_FUEL_CHANGE_RATIO = 0.99;
    const double DEFAULT_ACCELERATION_RATIO = 1.1;
    const qint32 START_INDEX_OF_COLLECTION = -1;
    const qint32 DEFAULT_VALUE = 0;
    const qint32 DEFAULT_SPEED = 0;
    const qint32 DEFAULT_ROTATION_ANGLE = 0;
    const qint32 DEFAULT_INDEX = 0;
    const qint32 DEFAULT_COORD = 0;
    const qint32 DEFAULT_WORK_TIME = 0;
    const qint32 DEFAULT_INSIDE_TEMPERATURE = 25;
    const qint32 DEFAULT_ENGINE_TEMPEATURE = 90;
    const QString DEFAULT_URL = "http:\\www.google.com";
    const QString DEFAULT_IMAGE_PATH = "\\image\\";
    const QString DEFAULT_AUDIO_FILE_PATH = "\\audio\\";
    const QString DEFAULT_LOGFILE_PATH= "logFile.txt";
    const QString EMPTY_STRING = "";

    const int COUNT_MILISECONDS = 1000;

    //-------------- indicators ID ---------------------------------------------
    const qint32 CLOCK_INDICATRO_ID = 100;
    const qint32 BROWSER_INDICATOR_ID  = 101;
    const qint32 RADIO_INDICATOR_ID = 102;
    const qint32 CAR_INFO_INDICATOR_ID = 103;
    const qint32 CLIMATE_CONTROL_INDICATOR_ID = 104;
    const qint32 TERMOMETR_INDICATOR_ID = 105;
    const qint32 SPEEDOMETR_INDICATOR_ID = 106;
    const qint32 STEERING_INDICATOR_ID = 107;
    const qint32 RIGHT_TURN_SIGNAL_INDICATOR_ID = 108;
    const qint32 LEFT_TURN_SIGNAL_INDICATOR_ID = 109;
    const qint32 OIL_IDICATOR_ID = 110;

    //------------ states ID  --------------------------------------------------

    const qint32 FSM_STOP_STATE = 400;
    const qint32 FSM_MOVE_STATE = 401;
    const qint32 FSM_ACCELERATE_STATE = 402;

    // error codes
    const qint32 COLLECTION_IS_EMPTY = 200;
    const qint32 FILE_NOT_OPEN = 201;
}
#endif // EMULATIONNAMESPACE_H
