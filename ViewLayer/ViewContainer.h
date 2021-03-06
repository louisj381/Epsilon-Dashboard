#pragma once

#include <QScopedPointer>

class DisplayDashboardView;
class I_DisplayDashboardUI;
class I_RaceModeDashboardUI;
class BatteryUi;
class ControlUi;
class HomePageUi;
class MotorFaultUi;
class MotorUi;
class MpptUi;
class OverlordWidget;
class TabUi;
class PresenterContainer;


enum class Mode { RACE, DISPLAY, DEBUG };

class ViewContainer
{
public:
    explicit ViewContainer(PresenterContainer& presenterContainer, Mode mode);
    ~ViewContainer();

private:
    I_DisplayDashboardUI* DisplayDashboardUI_;
    I_RaceModeDashboardUI* RaceModeDashboardUI_;
    BatteryUi* batteryUi_;
    ControlUi* controlUi_;
    HomePageUi* homepageUi_;
    MotorFaultUi* motorFaultUi_;
    MotorUi* motorUi_;
    MpptUi* mpptUi_;
    TabUi* tabUi_;
    QScopedPointer<DisplayDashboardView> DisplayDashboardView_;
    QScopedPointer<OverlordWidget> overlordWidget_;
};
