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

		void startNote(int midiNoteNumber, float velocity, SynthesiserSound* sound,
			int currentPitchWheelPosition)
		{
			frequency = MidiMessage::getMidiNoteInHertz(midiNoteNumber);
			Logger::outputDebugString(std::to_string(midiNoteNumber));
		}

		//=========================================

		void stopNote(float velocity, bool allowTailOff)
		{
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
				double theWave = osc1.sinewave(440);

				for (int channel = 0; channel < outputBuffer.getNumChannels(); ++channel)
				{
					outputBuffer.addSample(channel, startSample, theWave);
				}

				++startSample;
			}
		}

		//=========================================

	private:
		double level;
		double frequency;

		maxiOsc osc1;
};