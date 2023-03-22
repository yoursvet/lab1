#include <iostream>

class Television {
private:
    bool power;
    int channel;

    friend class Remote; // объявление класса Remote как друга класса Television

public:
    Television() : power(false), channel(0) {}

    bool isOn() const {
        return power;
    }

    int getChannel() const {
        return channel;
    }

    void turnOn() {
        power = true;
    }

    void turnOff() {
        power = false;
    }

    void setChannel(int channel) {
        this->channel = channel;
    }
};

class Remote {
private:
    Television& television;

public:
    Remote(Television& television) : television(television) {}

    void pressPowerButton() {
        if (television.isOn()) {
            television.turnOff();
            std::cout << "Телевизор выключен" << std::endl;
        } else {
            television.turnOn();
            std::cout << "Телевизор включен" << std::endl;
        }
    }

    void pressChannelButton(int channel) {
        television.setChannel(channel);
        std::cout << "Переключение на канал " << channel << std::endl;
    }
};

int main() {
    Television tv;
    Remote remote(tv);

    remote.pressPowerButton(); 
    remote.pressChannelButton(5); 
    remote.pressPowerButton(); 

    return 0;
}