#include "Signal.h"
#include <string>
#include <iostream>
#include <fstream>    


void Signal::fill(){
	for(int i = 0; i < samples; i++){
		signalPtr[i] = 0;
    }
}

void Signal::fillTime(){
	for(int i = 0; i < samples; i++){
		double N = i/1.0;
		timePtr[i] = initial_time + (i/frequency);
	}
}

        

 
Signal::Signal(){
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

        //overloaded constructor
Signal::Signal(int size, double freq, double time){
	samples = size;
	frequency = freq;
	initial_time = time;
	//these are the same in both constructors
	signalPtr = new double[samples];
	timePtr = new double[samples];
	filename = "tsdig";

	//filling arrays. 
	fill();
	fillTime();

}

void Signal::round(){
	for(int i = 0; i < samples; i++){
		signalPtr[i] = std::round(signalPtr[i]);
	}
}

void Signal::fillSin(double A, double f, double phi){
	for(int i = 0; i < samples; i++){
		signalPtr[i] = A * cos(2 * M_PI * f * timePtr[i] + phi);
	}
}

Signal::~Signal(){
	delete signalPtr;
	delete timePtr;
}

//mutator functions
void Signal::setSamples(int size){
	samples = size;
}

void Signal::setFreq(double freq){
	frequency = freq;
}

void Signal::setTime(double time){
	initial_time = time;
}

void Signal::setFileName(std::string address){
	filename = address;
}

//accessor functions
int Signal::getSamples(){
	return samples;
}

double Signal::getFreq(){
	return frequency;
}

double Signal::getTime(){
	return initial_time;
}

double* Signal::getPtr(){
	return signalPtr;
}

double* Signal::getTptr(){
	return timePtr;
}


//other functions
void Signal::txt(){
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

void Signal::plot(){
	/*
	//mgl data objects to interface with the rest of the class
	mglData Mtime(samples), Msignals(samples);
	Mtime.Set(timePtr, samples);
	Msignals.Set(signalPtr, samples);
	
	mglGraph gr;
	gr.Title("The Title Goes Here");
	gr.SetRanges(initial_time, timePtr[samples-1], Msignals.Minimal(), Msignals.Maximal());
	gr.SetOrigin(0, 0);
	
	gr.Axis();
	gr.Puts(mglPoint(-0.04, 0.3), mglPoint(0.04, 0.3), "x(t)");
	
	gr.Puts(mglPoint(-0.01, 2), mglPoint(-0.01, 3), "t");

	gr.Plot(Mtime, Msignals);
	
	std::string address = "ICA10_Plot";
	const char* png = (address + ".png").c_str();
	const char* eps = (address + ".eps").c_str();
	gr.WriteEPS(eps);
	gr.WritePNG(png);
	*/
}	



