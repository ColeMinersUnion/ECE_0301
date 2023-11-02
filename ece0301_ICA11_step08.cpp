#include <string>
#include <vector>
#include <fstream>

class Signal{
    private:
        int size;
        double sampling_freq, init_time;
        std::string label, file, equation;
        std::vector<double> time, sample; //

        void fillTime(){
            for(int i = 0; i < size; i++){
                time.push_back(init_time + (i/sampling_freq));
                sample.push_back(0);
            }
        }

    public:
        Signal(){
            size = 101; 
            sampling_freq = 100;
            init_time = 0;
            equation = "0";
            setLbl("x");
            fillTime();
        }

        Signal(int samples, double sfreq, double time, std::string lbl){
            size = samples;
            sampling_freq = sfreq;
            init_time = time;
            equation = "0";
            setLbl(lbl);
            fillTime();
        }

        //mutator and accessor functions
        void setSize(int samples){
            size = samples;
        }

        void setFreq(double freq){
            sampling_freq = freq;
        }

        void setTime(double time){
            init_time = time;
        }

        void setEq(std::string Eq){
            equation = Eq;
        }

        int getSize(){
            return size;
        }

        double getFreq(){
            return sampling_freq;
        }

        double getTime(){
            return init_time;
        }

        std::string getEq(){
            return equation;
        }

        std::vector<double> getTimeV(){
            return time;
        }

        std::vector<double> getSampV(){
            return sample;
        }

        double getTimeV(unsigned int n){
            return time[n];
        }

        double getSampV(unsigned int n){
            return sample[n];
        }

        void setLbl(std::string newLbl){
            label = newLbl;
            file = "signal_" + label;
        }

        void output(){
            std::ofstream outfile;
            outfile.open(file + ".txt");

            outfile << "Time-Domain Signal Samples\n";
            outfile << "N = " << size << std::endl;
            outfile << "fs = " << sampling_freq << std::endl;
            outfile << "t0 = " << init_time << std::endl;
            outfile << "Signal label: " << label + "\n";
            outfile << "Mathematical Expression\n";
            outfile << label << "(t) = " << equation << std::endl;
            outfile << "Time and Signal samples in .csv format\n";
            outfile << "-------\n";

            for(int i = 0; i < size; i++){
                outfile << time[i] << ", " << sample[i] << std::endl;
            }

            outfile.close();
        }

};


int main(){
    Signal X;
    X.output();

    Signal Y(401, 10000, -0.01, "y");
    Y.output();
}