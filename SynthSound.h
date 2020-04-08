/*
  ==============================================================================

    SynthSound.h
    Created: 6 Apr 2020 9:16:54pm
    Author:  Haukn

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

class SynthSound : public SynthesiserSound
{
	public:
		bool appliesToNote(int /*midiNoteNumber*/)
		{
			return true;
		}

		bool appliesToChannel(int /*midiChannel*/)
		{
			return true;
		}
};
