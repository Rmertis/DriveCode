#include <iostream>
#include <memory>
#include <string>

#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>

#include <cstdlib>
#include <Joystick.h>
#include <RobotDrive.h>
#include <CANTalon.h>

class Robot: public frc::IterativeRobot {
public:
	void RobotInit() {
//drive
		myDrive = new RobotDrive (fL,fR,bR,bL);
		myDrive->SetExpiration (1000);

	}


	void AutonomousInit() override {

	}

	void AutonomousPeriodic() {

	}

	void TeleopInit() {

	}

	void TeleopPeriodic() {
		//Drive
		if(stick->GetRawAxis(2) > .1)
		{
			myDrive->Drive(stick->GetRawAxis(3)-stick->GetRawAxis(2), stick->GetRawAxis(0));		}
		else if (stick->GetRawAxis(3) > .10)
		{
			myDrive->Drive(stick->GetRawAxis(3)-stick->GetRawAxis(2), stick->GetRawAxis(0));
		}
		else
		{
			myDrive->SetLeftRightMotorOutputs(stick->GetRawAxis(0), -stick->GetRawAxis(0));
		}
	}
	void TestPeriodic() {
		lw->Run();
	}

private:
	frc::LiveWindow* lw = LiveWindow::GetInstance();

	//Drive Stuff
	RobotDrive *myDrive;
	CANTalon *fL = new CANTalon(15);
	CANTalon *fR = new CANTalon(0);
	CANTalon *bL = new CANTalon(14);
	CANTalon *bR = new CANTalon(1);

	//Joysticks
	Joystick *stick = new Joystick (0);

};

START_ROBOT_CLASS(Robot)
