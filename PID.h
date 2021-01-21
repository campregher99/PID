#ifndef PID_H

#define PID_H
#define DOUBLE double

#include "Double.h"
#include "OutputArduino.h"
#include "TimerArduino.h"
class PID
{
private:
	DOUBLE kp{0};
	DOUBLE ki{0};
	DOUBLE kd{0};
	DOUBLE err{0};
	DOUBLE i{0};
	DOUBLE desVal{0};
	DOUBLE actVal{0};
	unsigned int division{0};
	Output* uscita = new OutputArduino;
	Timer* timer = new TimerArduino;
	unsigned long int period{0};
public:
	PID() = default;
	PID(const DOUBLE& _kp, const DOUBLE& _ki = 0, const DOUBLE& _kd = 0);
	~PID()=default;

	DOUBLE getKp() const;
	DOUBLE getKi() const;
	DOUBLE getKd() const;
	DOUBLE getErr() const;
	DOUBLE getI() const;
	DOUBLE getDesVal() const;
	DOUBLE getActVal() const;
	unsigned int getDivision() const;
	unsigned long int getPeriod() const;

	bool setKp(const DOUBLE& _kp);
	bool setKi(const DOUBLE& _ki);
	bool setKd(const DOUBLE& _kd);
	bool setErr(const DOUBLE& _err);
	bool setI(const DOUBLE& _i);
	bool setDesVal(const DOUBLE& _desVal);
	bool setActVal(const DOUBLE& _actVal);
	bool setDivision(const unsigned int& _division);
	bool setPeriod(const unsigned long int& _period);
	bool resetErr();
	bool resetI();
	bool generatePWM();
	bool calculateErr();
	bool autoKSet();
	DOUBLE derivate();
	bool setStep(unsigned int& _step);
	unsigned int getStep();
};

#endif
