#pragma once
#include "I_MotorFaultUi.h"
namespace Ui
{
    class MotorFaultUi;
}
class MotorFaultUi : public I_MotorFaultUi
{
    Q_OBJECT
public:
    explicit MotorFaultUi();
    ~MotorFaultUi();
    QLabel& titleLabel();
private:
    Ui::MotorFaultUi* ui_;
};
