#ifndef Signal_H
#define Signal_H
#include <string>
class Signal{
	private:
        unsigned int samples;
        double frequency, initial_time; //in Hz and Seconds
        double* signalPtr;
        double* timePtr;
        std::string filename;
        
        void fill();
        void fillTime();
	
	public:
		Signal();
		Signal(int, double, double);
		void round();
		void fillSin(double, double, double);
		~Signal();
		void setSamples(int);
		void setFreq(double);
		void setTime(double);
		void setFileName(std::string);
		int getSamples();
		double getFreq();
		double getTime();
		double* getPtr();
		double* getTptr();
		
		void txt();
		void plot();
};


#endif
