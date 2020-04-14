/*
  ==============================================================================

    Envelope.cpp
    Created: 13 Apr 2020 10:01:52pm
    Author:  Haukn

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Envelope.h"

//==============================================================================
Envelope::Envelope(SynthFrameworkAudioProcessor& p) : 
    processor(p)
{
    setSize(200, 200);
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.

    attackSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    attackSlider.setRange(0.1f, 5000.0f); // 5000 ms
    attackSlider.setValue(0.1f);
    attackSlider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
    attackSlider.addListener(this);
    addAndMakeVisible(&attackSlider);

    decaySlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    decaySlider.setRange(1.0f, 2000.0f);
    decaySlider.setValue(1.0f);
    decaySlider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
    decaySlider.addListener(this);
    addAndMakeVisible(&decaySlider);

    sustainSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    sustainSlider.setRange(0.0f, 1.0f);
    sustainSlider.setValue(0.8f);
    sustainSlider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
    sustainSlider.addListener(this);
    addAndMakeVisible(&sustainSlider);

    releaseSlider.setSliderStyle(Slider::SliderStyle::LinearVertical);
    releaseSlider.setRange(0.1f, 5000.0f);
    releaseSlider.setValue(0.1f);
    releaseSlider.setTextBoxStyle(Slider::NoTextBox, true, 0, 0);
    releaseSlider.addListener(this);
    addAndMakeVisible(&releaseSlider);



    attackTree = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "attack", attackSlider);
    decayTree = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "decay", decaySlider);
    sustainTree = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "sustain", sustainSlider);
    releaseTree = new AudioProcessorValueTreeState::SliderAttachment(processor.tree, "release", releaseSlider);


    
}

Envelope::~Envelope()
{
}

void Envelope::paint (Graphics& g)
{
    g.fillAll(Colours::black);
}

void Envelope::resized()
{
    juce::Rectangle<int> area = getLocalBounds().reduced(40);

    attackSlider.setBounds(10, 10, 40, 100);
    decaySlider.setBounds(60, 10, 40, 100);
    sustainSlider.setBounds(110, 10, 40, 100);
    releaseSlider.setBounds(160, 10, 40, 100);
    // This method is where you should set the bounds of any child
    // components that your component contains..

}

void Envelope::sliderValueChanged(Slider* slider)
{
}