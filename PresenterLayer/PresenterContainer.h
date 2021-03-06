#pragma once

#include <QScopedPointer>

class BusinessContainer;
class CommunicationContainer;
class DataContainer;

class BatteryPresenter;
class BatteryFaultsPresenter;
class DriverControlsPresenter;
class KeyMotorPresenter;
class LightsPresenter;
class MpptPresenter;
class MotorDetailsPresenter;
class MotorFaultsPresenter;

class PresenterContainer
{
public:
    PresenterContainer(DataContainer& dataContainer);
    ~PresenterContainer();
    BatteryPresenter& batteryPresenter();
    BatteryFaultsPresenter& batteryFaultsPresenter();
    DriverControlsPresenter& driverControlsPresenter();
    KeyMotorPresenter& keyMotorPresenter();
    LightsPresenter& lightsPresenter();
    MpptPresenter& mpptPresenter();
    MotorDetailsPresenter& motorDetailsPresenter();
    MotorFaultsPresenter& motorFaultsPresenter();


private:
    QScopedPointer<BatteryPresenter> batteryPresenter_;
    QScopedPointer<BatteryFaultsPresenter> batteryFaultsPresenter_;
    QScopedPointer<DriverControlsPresenter> driverControlsPresenter_;
    QScopedPointer<KeyMotorPresenter> keyMotorPresenter_;
    QScopedPointer<LightsPresenter> lightsPresenter_;
    QScopedPointer<MpptPresenter> mpptPresenter_;
    QScopedPointer<MotorDetailsPresenter> motorDetailsPresenter_;
    QScopedPointer<MotorFaultsPresenter> motorFaultsPresenter_;
};
