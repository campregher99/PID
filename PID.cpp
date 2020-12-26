#include "PID.h"

PID(const DOUBLE& _kp, const DOUBLE& _ki = 0, const DOUBLE& _kd = 0)
{
	#if DOUBLE == Double
	Double::setMultiplier(10000);
	#endif
	kp=_kp;
	ki=_ki;
	kd=_kd;
}

DOUBLE getKp() const
{
	return kp;
}

DOUBLE getKi() const
{
	return ki;
}

DOUBLE getKd() const
{
	return kd;
}

DOUBLE getErr() const
{
	return err;
}

DOUBLE getI() const
{
	return i;
}

DOUBLE getDesVal() const
{
	return desVal;
}

DOUBLE getActVal() const
{
	return actVal;
}

unsigned int getDivision() const
{
	return division;
}

bool setKp(const DOUBLE& _kp)
{
	kp=_kp;
	return true;
}

bool setKi(const DOUBLE& _ki)
{
	ki=_ki;
	return true;
}

bool setKd(const DOUBLE& _kd)
{
	kd=_kd;
	return true;
}

bool setErr(const DOUBLE& _err)
{
	err=_err;
	return true;
}

bool setI(const DOUBLE& _i)
{
	i=_i;
	return true;
}

bool setDesVal(const DOUBLE& _desVal)
{
	desVal=_desVal;
	return true;
}

bool setActVal(const DOUBLE& _actVal)
{
	sctVal=_actVal;
	return true;
}

bool setDivision(const unsigned int& _division)
{
	division=_division;
	return true;
}

bool resetErr()
{
	err=0;
	return true;
}

bool resetI()
{
	i=0;
	return true;
}

DOUBLE generatePWM()
{
	return err*kp + i*ki + derivate()*kd;
}

bool calculateErr()
{
	err=desVal-actVal;
	return true;
}

bool autoKSet()
{
	return false;
}

DOUBLE derivate()
{
	static DOUBLE prevVal;
	DOUBLE derivate{actVal-prevVal};
	prevVal = actVal;
	return derivate;
}