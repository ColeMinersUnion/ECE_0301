#include <string>
#include <vector>
#include <fstream>
#include <cmath>
#include <mgl2/mgl.h>
#include <math.h>

class Signal{
    private:
        int size;
        double sampling_freq, init_time;
        std::string label, file, equation;
        std::vector<double> time, sample; //

        
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
		
		void fillTime(){
            for(int i = 0; i < size; i++){
                time.push_back(init_time + (i/sampling_freq));
                sample.push_back(0);
            }
        }
        
        void sinWave(double Amplitude, double freq, double phi){
			for(int i = 0; i < size; i++){
				sample[i] = Amplitude * std::cos(2 * M_PI * freq * time[i] + phi);
			}
		}
		
		void roundWave(){
			for(int i = 0; i < size; i++){
				sample[i] = std::round(sample[i]);
			}
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
        
        void constant(double K){
			for(int i = 0; i < size; i++){
				sample[i] = K;
			}
			equation = std::to_string(K);
		}

		std::string textNum(double x) const{
			if(x >= 100){
				return std::to_string(int(x));
			} else {
				std::string x_exp = std::to_string(x);
				return x_exp.substr(0, 4 + (x<0));
			}
		}
		
		void plot(){
			mglData Mtime(size);
			mglData Msamp(size);
			for(int i = 0; i < size; i++){
				Mtime.a[i] = time[i];
				Msamp.a[i] = sample[i];
			}
			
			//graph time
			mglGraph gr;
			std::string title = label + "(t) = " + std::string(equation);
			gr.Title(title.c_str());
			gr.SetRanges(init_time, time[size-1], Msamp.Minimal()-1, Msamp.Maximal()+1);
			gr.SetOrigin(0, 0);
			gr.Axis();
			gr.Plot(Mtime, Msamp);
			
			std::string address = "signal_" + label;
			
			const char* png = (address + ".png").c_str();
			const char* eps = (address + ".eps").c_str();
			gr.WriteEPS(eps);
			gr.WritePNG(png);
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

		Signal operator=(Signal& obj){
			size = obj.size;
			sampling_freq = obj.sampling_freq;
			init_time = obj.init_time;
			label = obj.label;
			equation = obj.equation;
			time = obj.time;
			sample = obj.sample;
			return *this;
		}
		
		Signal operator+(Signal &obj){
			Signal newSig = obj;
			for(int i = 0; i < size; i++){
				newSig.getSampV()[i] = obj.getSampV()[i] + getSampV()[i];
			}
			return newSig;
		}
		
};


int main(){
    Signal X(401, 10000, -0.01, "X");
    X.sinWave(100, 200, -M_PI/2);
    X.output();
    X.plot();
    
    Signal Y(401, 10000, -0.01, "Y");
    Y.constant(250);
    Y.output();
    Y.plot();
    
    Signal Z = X + Y;
    Z.setLbl("Z");
    //Z.roundWave();
    Z.output();
    Z.plot();

    
    

    Y.output();
    Y.plot();
}
