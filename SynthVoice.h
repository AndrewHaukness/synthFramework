/*
  ==============================================================================

    SynthVoice.h
    Created: 6 Apr 2020 9:17:04pm
    Author:  Haukn

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "SynthSound.h"
#include "maximilian.h"

class SynthVoice : public SynthesiserVoice
{
	public:


		//dynamic cast returns true if the sound is casted as a SynthSound
		bool canPlaySound(SynthesiserSound* sound)
		{
			return dynamic_cast<SynthSound*>(sound) != nullptr;
		}

		//=========================================

		void getEnvelopeParams(float* attack, float* decay, float* sustain, float* release)
		{
			env1.setAttack(double(*attack)); //2000 ms =  2s
			env1.setDecay(double(*decay));
			env1.setSustain(double(*sustain)); // sustain is value from 0 to 1
			env1.setRelease(double(*release));

		}

		//=========================================

		void getOscType(float* selection)
		{
			theWave = *selection;
		}

		double setOscType()
		{
			if (theWave == 0)
			{
				return osc1.sinewave(frequency);
			}
			if (theWave == 1)
			{
				return osc1.saw(frequency);
			}
			if (theWave == 2)
			{
				return osc1.square(frequency);
			}
			else
			{
				return osc1.sinewave(frequency);
			}
		}

		//=========================================

		void startNote(int midiNoteNumber, float velocity, SynthesiserSound* sound,
			int currentPitchWheelPosition)
		{
			env1.trigger = 1;
			level = velocity;
			frequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
		}

		//=========================================

		void stopNote(float velocity, bool allowTailOff)
		{
			env1.trigger = 0;
			allowTailOff = true;

			if ( velocity == 0 )
				clearCurrentNote();
		}

		//=========================================

		void pitchWheelMoved(int newPitchWheelValue)
		{

		}

		//=========================================

		void controllerMoved(int controllerNumber, int newControllerValue)
		{

		}

		//=========================================

		void renderNextBlock(AudioBuffer<float>& outputBuffer, int startSample, int numSamples)
		{



			for (int sample = 0; sample < numSamples; ++sample)
			{
				//double theWave = osc1.sinewave(frequency);
				double theSound = env1.adsr(setOscType(), env1.trigger) * level;
				//double filteredSound = filter1.lores(theSound, 100, 0.1);

				for (int channel = 0; channel < outputBuffer.getNumChannels(); ++channel)
				{
					outputBuffer.addSample(channel, startSample, theSound);
				}

				++startSample;
			}
		}

		//=========================================

	private:
		double level;
		double frequency;

		int theWave;

		maxiOsc osc1;
		maxiEnv env1;
		maxiFilter filter1;
};