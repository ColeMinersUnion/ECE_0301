#include <iostream>
#include <string>
#include <fstream>



class Signal{

    private:
        unsigned int samples;
        double frequency, initial_time; //in Hz and Seconds
        double* signalPtr;
        double* timePtr;
        std::string filename;


        void fill(){
            for(int i = 0; i < samples; i++){
                signalPtr[i] = 0;
            }
        }

        void fillTime(){
            for(int i = 0; i < samples; i++){
                double N = i/1.0;
                timePtr[i] = initial_time + (i/frequency);
            }
        }

    public:
        Signal(){
            samples = 101;
            frequency = 100;
            initial_time = 0.0;
            signalPtr = new double[samples];
            timePtr = new double[samples];
            filename = "tsdig";

            //filling arrays. 
            fill();
            fillTime();
        }

        ~Signal(){
            delete signalPtr;
            delete timePtr;
        }

        //mutator functions
        void setSamples(int size){
            samples = size;
        }

        void setFreq(double freq){
            frequency = freq;
        }

        void setTime(double time){
            initial_time = time;
        }

        void setFileName(std::string address){
            filename = address;
        }

        //accessor functions
        int getSamples(){
            return samples;
        }

        double getFreq(){
            return frequency;
        }

        double getTime(){
            return initial_time;
        }

        double* getPtr(){
            return signalPtr;
        }

        double* getTptr(){
            return timePtr;
        }


        //other functions
        void txt(){
            std::ofstream output;
            output.open(filename + ".txt");

            output << "ECE 0301: Time-Domain Signal Samples\n";
            output << "The number of samples is " << samples << std::endl;
            output << "The sample rate is " << frequency << std::endl;
            output << "The inital time is " << initial_time << std::endl;

            for(int i = 0; i < samples; i++){
                output << timePtr[i] << ", " << signalPtr[i] << std::endl;
            }

            output.close();
        }
};

int main(){

    Signal MySignal;

    MySignal.setFileName("time_domain_signal_samples");
    MySignal.txt();

    return 0;
}