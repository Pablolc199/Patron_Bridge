//Lopez Chavez Pablo
#include<iostream>
#include<math.h>
#include<vector>
#include<list>
using namespace std;
class Device {
public:
	virtual bool isEnabled(bool a) = 0;
	virtual void enable() = 0;
	virtual void disable() = 0;
	virtual int getVolume() = 0;
	virtual void setVolume(int percent) = 0;
	virtual int getChannel() = 0;
    virtual float getChannelFloat()=0;
	virtual void setChannel(int channel) = 0;
    virtual void setChannelFloat(float channel)=0;
    
};
class RemoteControl{
public:
    bool a=1;
	Device* device;
	RemoteControl();
	RemoteControl(Device* de){
		this->device=de;
	}
	bool togglePower(){
		if(device->isEnabled(a)){
			device->disable();
            a=0;
            return 1;
		}else {
			device->enable();
            a=1;
            return 0;
		}
	}
	void volumeDown(){
		device->setVolume(device->getVolume()-10);
	}
	void volumeUp(){
		device->setVolume(device->getVolume()+10);
	}
	void channelDown(){
		device->setChannel(device->getChannel()-1);
	}
	void channelUp(){
		device->setChannel(device->getChannel()+1);
	}
    void channelUpRadio(){
        device->setChannelFloat(device->getChannelFloat()+0.5);
    }
    void channelDownRadio(){
        device->setChannelFloat(device->getChannelFloat()-0.5);
    }
};
class AdvancedRemoteControl : public RemoteControl {
public:
    AdvancedRemoteControl(Device* device): RemoteControl(device){}
    void mute() {
        device->setVolume(0);
    }
};
class Tv : public Device {
    public:
    string marca;
    vector<string>ListaCanales;
    int vol=0;
    int canal=0;
    Tv(string marca){
        this->marca=marca;
    }
    string getMarca(){
        return marca;
    }
	bool isEnabled(bool a) override {
        if(a==1){
            return 1;
        }else {
            return 0;
        }

	}
	void enable() override {
        cout<<"La Tv esta hablilitada"<<endl;
		cout<<"Prendido TV"<<endl;
        
	}

	void disable() override {
        cout<<"La Tv esta inhabilitada"<<endl;
		cout<<"Apagado Tv"<<endl;
	}
	int getVolume() override {
        return vol;
    }

    void setVolume(int percent) override {
        vol= percent;
    }

    int getChannel() override {
        return canal;
    }
    float getChannelFloat() override{
        return 0;
    }
    void setChannel(int channel) override {
        canal=channel;
    }
    void VerListaCanales(){
        for(int i=0; i<ListaCanales.size(); i++)
        {
            cout<<"********************"<<endl;
            cout<<(i+1)<<".- ";
            cout<<ListaCanales[i]<<endl;
        }
    }
    void VerCanal(int r){
        for(int i=0;i<=ListaCanales.size();i++){
            if(i==r){
                cout<<(i)<<".- ";
                cout<<ListaCanales[i-1]<<endl;
                return;
            }
        }
    }
    void setChannelFloat(float channel) override{
        cout<<"no disponible";
    }
};
class Radio : public Device {
public:
    int vol=0;
    float canal=0;
	bool isEnabled(bool a) override {
        if(a==1){
            return 1;
        }else {
            return 0;
        }

	}
	void enable() override {
        cout<<"La Radio esta hablilitada"<<endl;
		cout<<"Prendido Radio"<<endl;
	}

	void disable() override {
        cout<<"La Radio esta inhabilitada"<<endl;
		cout<<"Apagado Radio"<<endl;
	}
	int getVolume() override {
	    return vol;
    }

    void setVolume(int percent) override {
        vol = percent;
    }

    int getChannel() override {
        return canal;
    }
    float getChannelFloat() override {
        return canal;
    }
    void setChannel(int channel) override {
        //canal=channel;
    }
    void setChannelFloat(float channel) override{
        canal=channel;
    }
};
class TvBox : public Device {
    public:
    int vol=0;
    int canal=0;
    string Servicio;
    string Peliculas;
	bool isEnabled(bool a) override {
        if(a==1){
            return 1;
        }else {
            return 0;
        }

	}

	void enable() override {
        cout<<"La Tv esta hablilitada"<<endl;
		cout<<"Prendido TV"<<endl;
        
	}

	void disable() override {
        cout<<"La Tv esta inhabilitada"<<endl;
		cout<<"Apagado Tv"<<endl;
	}
	int getVolume() override {
        return vol;
    }
    void setVolume(int percent) override {
        vol= percent;
    }
    //No se utilizara
    int getChannel() override {
        return canal;
    }
    float getChannelFloat() override{
        return 0;
    }
    void setChannel(int channel) override {
        canal=channel;
    }
    void setChannelFloat(float channel) override{
        cout<<"no disponible";
    }
    //Recien desde esta parte se utilizara
    void VerListaServicios(){
        Servicio= "Netflix";

    }
    void VerPeliculas(){
        Peliculas="Pinocho";
    }
};
int main(){
	int op, ps=0;
    int q;
    //Se creo un untero de tipo tv dondede se puede hacer todas las funcines con el control
    // Como tambien consultar cosas de la tele, como lista de canales
	Tv* tele=new Tv("sony");

    tele->ListaCanales.push_back("disney");
    tele->ListaCanales.push_back("Cartoon Network");
    tele->ListaCanales.push_back("TLC");
    tele->ListaCanales.push_back(" History");
    tele->ListaCanales.push_back("STAR Channel");


    //Para ecender la Tv se necesita pulsar dos veces 1 porque en la primera se habilita pero esta apagada y en la segunda
    //ya se prende
	RemoteControl* remote= new RemoteControl(tele);
    cout<<"La marca de la Tv es "<<endl;
    cout<< tele->getMarca()<<endl;
    do
    {
        cout<<"1.-Quiere apretar el boton de encendido"<<endl;
        cout<<"2.-Salir"<<endl;
        cin>>op;
        if(op==2){
            break;;
        }
        if(remote->togglePower()){
            cout<<"incapaz de realizar operaciones"<<endl;
        }else {
            do
            {
                cout<<"Que operacion desea realizar ?"<<endl;
                cout<<"1.- Subir volumen"<<endl;
                cout<<"2.-Bajar volumen"<<endl;
                cout<<"3.- Ver lista de canales"<<endl;
                cout<<"4.- Cambiar canal (arriba)"<<endl;
                cout<<"5.- Cambiar canal (abajo)"<<endl;
                cout<<"6.-salir"<<endl;
                cin>>q;
                cout<<"***************************************"<<endl;
                if(q==1){
                    remote->volumeUp();
                    cout<<tele->getVolume()<<endl;
                }else if(q==2){
                    if(tele->getVolume()==0){
                        cout<<"no se puede bajar mas"<<endl;
                    }else {
                        remote->volumeDown();
                        cout<<tele->getVolume()<<endl;
                    }
                }else if(q==3){
                    tele->VerListaCanales();
                }else if(q==4){
                    if(tele->getChannel()==5){
                        cout<<"No se puede subir más "<<endl;
                    }else {
                        remote->channelUp();
                        cout<<tele->getChannel()<<endl;
                        tele->VerCanal(tele->getChannel());
                        cout<<endl;
                        cout<<"*****************"<<endl;
                    }
                }else if(q==5){
                    if(tele->getChannel()==1){
                        cout<<"no se puede bajar más"<<endl;
                    }else {
                        remote->channelDown();
                        cout<<tele->getChannel()<<endl;
                        tele->VerCanal(tele->getChannel());
                        cout<<endl;
                        cout<<"*****************"<<endl;
                    }
                }
            } while (q!=6);
            

        }
    } while (op!=2);
    cout<<"Esta entrando a la Radio"<<endl;
    op=0;
    Radio* radio = new Radio();
    AdvancedRemoteControl* control = new AdvancedRemoteControl(radio);
    //Para ecender la radio se necesita pulsar dos veces 1 porque en la primera se habilita pero esta apagada y en la segunda
    //ya se prende
    do
    {
        cout<<"1.-Quiere apretar el boton de encendido"<<endl;
        cout<<"2.-Salir"<<endl;
        cin>>op;
        if(control->togglePower()){
            cout<<"Incapaz de realizar operaciones en la Radio"<<endl;
            //Se usa el control para encender la Radio;
        }else {
            do
            {
                cout<<"Que operacion desea realizar ?"<<endl;
                cout<<"1.- Subir volumen"<<endl;
                cout<<"2.-Bajar volumen"<<endl;
                cout<<"3.- Mute"<<endl;
                cout<<"4.- Cambiar canal (arriba)"<<endl;
                cout<<"5.- Cambiar canal (abajo)"<<endl;
                cout<<"6.- Salir"<<endl;
                cin>>q;
                if(q==1){
                    control->volumeUp();
                    cout<<radio->getVolume()<<endl;
                }else if(q==2){
                    if(radio->getVolume()==0){
                        cout<<"no se puede bajar mas"<<endl;
                    }else {
                        control->volumeDown();
                        cout<<radio->getVolume()<<endl;
                    }
                }else if(q==3){
                    control->mute();
                }else if(q==4){
                    control->channelUpRadio();
                    cout<<radio->getChannelFloat()<<endl;
                }else if(q==5){
                    if(radio->getChannelFloat()==0){
                        cout<<"No se puede reducir mas el canal"<<endl;
                    }else {
                        control->channelDownRadio();
                        cout<<radio->getChannelFloat()<<endl;
                    }
                }
            } while (q!=6);
        }
        
    } while (op!=2);
    TvBox* xiaomi=new TvBox();


    RemoteControl* mando=new RemoteControl(xiaomi);
    do
    {
        cout<<"1.-Quiere apretar el boton de encendido"<<endl;
        cout<<"2.-Salir"<<endl;
        cin>>op;
        if(op==2){
            break;;
        }
        if(mando->togglePower()){
            cout<<"incapaz de realizar operaciones"<<endl;
        }else {
            do
            {
                cout<<"Que operacion desea realizar ?"<<endl;
                cout<<"1.- Subir volumen"<<endl;
                cout<<"2.-Bajar volumen"<<endl;
                cout<<"3.- Ver lista de Peliculas"<<endl;
                cout<<"4.- Ver lista de eliculas de un servicio"<<endl;
                cout<<"5.-salir"<<endl;
                cin>>q;
                cout<<"***************************************"<<endl;
                if(q==1){
                    remote->volumeUp();
                    cout<<tele->getVolume()<<endl;
                }else if(q==2){
                    if(xiaomi->getVolume()==0){
                        cout<<"no se puede bajar mas"<<endl;
                    }else {
                        remote->volumeDown();
                        cout<<xiaomi->getVolume()<<endl;
                    }
                }else if(q==3){
                    xiaomi->VerListaServicios();
                }else if(q==4){
                    xiaomi->VerPeliculas();
                }
            } while (q!=5);
            

        }
    } while (op!=2);
	return 0;
}