#include <iostream>
#include <memory>

class SignalProcessor {
public:
    SignalProcessor() {
        std::cout << "Signal processor wired up!\n";
    }

    ~SignalProcessor() {
        std::cout << "Signal processor safely dismantled!\n";
    }

    void ProcessData() {
        std::cout << "Crunching numbers\n";
    }
};

class RadarStation {
private:
    std::unique_ptr<SignalProcessor> processor;

public:
    RadarStation() {
        std::cout << "Radar station constructed\n";
        processor = std::make_unique<SignalProcessor>();
    }
    ~RadarStation() {
        std::cout << "Radar station destroyed\n";
    }

    void RunScan() {
        std::cout << "Running scan!\n";
            processor -> ProcessData();
    }
};

int main()
{
    std::cout << "Booting System\n";

    // Create scope
    {
        // Unique smart pointer
        std::unique_ptr<RadarStation> radarStation = std::make_unique<RadarStation>();
        radarStation -> RunScan();
    }

    std::cout << "System Offline";
}