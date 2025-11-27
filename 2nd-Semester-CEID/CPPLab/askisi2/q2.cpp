 #include<iostream>

using namespace std;

class Kouti{
private:
	double mikos = 2.0;
	double platos;
	double ipsos;
public:
	void setMikos(double mik){
		mikos = mik;
	}

	void setPlatos(double pla){
		platos = pla;
	}

	void setIpsos(double ips);

	double getMikos(){
		return mikos;
	}

	double getPlatos(){
		return platos;
	}

	double getIpsos();
};

void Kouti::setIpsos(double ips){
	ipsos = ips;;
}

double Kouti::getIpsos(){
	return ipsos;
}

int main(){
	Kouti Small;
	Kouti Big;
	double ogkos = 0.0;
	Small.setPlatos(1.0);
	Small.setIpsos(2.0);
	ogkos = Small.getMikos() * Small.getPlatos() * Small.getIpsos();
	cout << "Ogkos gia small Kouti: " << ogkos << endl;

	Big.setMikos(12.0);
	Big.setPlatos(13.0);
	Big.setIpsos(10.0);
	ogkos = Big.getMikos() * Big.getPlatos() * Big.getIpsos();
	cout << "Ogkos gia big Kouti: " << ogkos << endl;
	return 0;
}
