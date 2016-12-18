#include<iostream>
using namespace std;

class Car
{
private:
	int gasolineGauge;
public:
	Car()
	{
		gasolineGauge = 10;
	}
	Car(int gas) : gasolineGauge(gas)
	{
		//empty
	}
	int GetGasGauge()
	{
		return gasolineGauge;
	}
};

class HybridCar : public Car
{
private:
	int electricGauge;
public:
	HybridCar(int gas, int elec) : Car(gas), electricGauge(elec)
	{
		//empty
	}
	int GetElecGauge()
	{
		return electricGauge;
	}
};

class HybridWaterCar : public HybridCar
{
private:
	int waterGauge;
public:
	HybridWaterCar(int gas, int elec, int water) : HybridCar(gas, elec), waterGauge(water)
	{
		//empty
	}
	void ShowCurrentGauge()
	{
		cout << "ÀÜ¿© °¡¼Ö¸° : " << GetGasGauge() << endl;
		cout << "ÀÜ¿© Àü±â·® : " << GetElecGauge() << endl;
		cout << "ÀÜ¿© ¿öÅÍ·® : " << waterGauge << endl;
	}
};

void main()
{
	Car car(40);
	HybridCar Hcar(40, 50);
	HybridWaterCar HWcar(40, 50, 60);

	cout << "car" << endl;
	cout << "ÀÜ¿© °¡¼Ö¸° : " << car.GetGasGauge() << endl << endl;
	cout << "Hcar" << endl;
	cout << "ÀÜ¿© °¡¼Ö¸° : " << Hcar.GetGasGauge() << endl;
	cout << "ÀÜ¿© Àü±â·® : " << Hcar.GetElecGauge() << endl << endl;
	cout << "HWcar" << endl;
	HWcar.ShowCurrentGauge();
}


