#ifndef DATACOLLECTOR_H
#define DATACOLLECTOR_H
#include "myo/myo.hpp"
#include <QDebug>
#include <QObject>
class QDataCollector: public QObject
{
    Q_OBJECT
signals:
    EMG( QVector<float>);
};

class DataCollector : public myo::DeviceListener
{

public:
QDataCollector qdc;
    DataCollector();

    void kick(int x);
    // onUnpair() is called whenever the Myo is disconnected from Myo Connect by the user.
    void onUnpair(myo::Myo* , uint64_t );

    // onEmgData() is called whenever a paired Myo has provided new EMG data, and EMG streaming is enabled.
    void onEmgData(myo::Myo* myo, uint64_t timestamp, const int8_t* emg);

    // There are other virtual functions in DeviceListener that we could override here, like onAccelerometerData().
    // For this example, the functions overridden above are sufficient.
    void onAccelerometerData(myo::Myo* myo, uint64_t timestamp, const myo::Vector3<float> &accel);

    void print();


    myo::Myo* myo;
    myo::Hub hub;
    QVector<float> emgSamples;               // The values of this array is set by onEmgData() above.
    QVector<float> emgSamplesD;               // The values of this array is set by onEmgData() above.
    QVector<float> accSamplesD;

};


#endif // DATACOLLECTOR_H
