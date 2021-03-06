#include "PID.h"

PID::PID(const DOUBLE& _kp, const DOUBLE& _ki , const DOUBLE& _kd )
{
	#if DOUBLE == Double
	Double::setMultiplier(10000);
	#endif
	kp=_kp;
	ki=_ki;
	kd=_kd;
}

DOUBLE PID::getKp() const
{
	return kp;
}

DOUBLE PID::getKi() const
{
	return ki;
}

DOUBLE PID::getKd() const
{
	return kd;
}

DOUBLE PID::getErr() const
{
	return err;
}

DOUBLE PID::getI() const
{
	return i;
}

DOUBLE PID::getDesVal() const
{
	return desVal;
}

DOUBLE PID::getActVal() const
{
	return actVal;
}

unsigned int PID::getDivision() const
{
	return division;
}

bool PID::setKp(const DOUBLE& _kp)
{
	kp=_kp;
	return true;
}

bool PID::setKi(const DOUBLE& _ki)
{
	ki=_ki;
	return true;
}

bool PID::setKd(const DOUBLE& _kd)
{
	kd=_kd;
	return true;
}

bool PID::setErr(const DOUBLE& _err)
{
	err=_err;
	return true;
}

bool PID::setI(const DOUBLE& _i)
{
	i=_i;
	return true;
}

bool PID::setDesVal(const DOUBLE& _desVal)
{
	desVal=_desVal;
	return true;
}

bool PID::setActVal(const DOUBLE& _actVal)
{
	actVal=_actVal;
	return true;
}

bool PID::setDivision(const unsigned int& _division)
{
	division=_division;
	return true;
}

bool PID::resetErr()
{
	err=0;
	return true;
}

bool PID::resetI()
{
	i=0;
	return true;
}

bool PID::generatePWM()
{
	static DOUBLE pwm {0};
	static unsigned int step {0};
	switch (step)
	{
		case 1:
			timer->setTimeMicros(period * pwm);
			timer->startCount();
			uscita->setOutput(1);
		break;
		case 2:
			calculateErr();
		break;
		case 3:
			i+=err;
		break;
		case 4:
			if(!timer->isPassed())
			{
				step--;
			} else
			{
				uscita->setOutput(0);
				timer->setTimeMicros(period * (1 - pwm));
				timer->startCount();
			}
		break;
		case 5:
			pwm = err*kp + i*ki + derivate()*kd;
		break;
		case 6:
			if(timer->isPassed())
				step = 0;
		break;
	}
	step++;
}

bool PID::calculateErr()
{
	err=desVal-actVal;
	return true;
}

bool PID::autoKSet()
{
	return false;
}

DOUBLE PID::derivate()
{
	static DOUBLE prevVal;
	DOUBLE derivate{actVal-prevVal};
	prevVal = actVal;
	return derivate;
}
