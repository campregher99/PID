#ifndef PID_H
#define PID_H 
#ifndef DOUBLE
#define DOUBLE double
#endif
#include "Double.h"
class PID
{
private:
	DOUBLE kp;
	DOUBLE ki;
	DOUBLE kd;
	DOUBLE err;
	DOUBLE i;
	DOUBLE desVal;
	DOUBLE actVal;
	unsigned int division;
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
	bool setKp(const DOUBLE& _kp);
	bool setKi(const DOUBLE& _ki);
	bool setKd(const DOUBLE& _kd);
	bool setErr(const DOUBLE& _err);
	bool setI(const DOUBLE& _i);
	bool setDesVal(const DOUBLE& _desVal);
	bool setActVal(const DOUBLE& _actVal);
	bool setDivision(const unsigned int& _division);
	bool resetErr();
	bool resetI();
	virtual DOUBLE generatePWM();
	virtual bool calculateErr();
	virtual bool autoKSet();
	virtual DOUBLE derivate();
};

#endif