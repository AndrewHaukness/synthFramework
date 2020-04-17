/*
  ==============================================================================

    Oscillator.cpp
    Created: 13 Apr 2020 9:04:46pm
    Author:  Haukn

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "Oscillator.h"

//==============================================================================
Oscillator::Oscillator(SynthFrameworkAudioProcessor& p):
    processor(p)
{
    setSize(200, 200);
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    oscMenu.addItem("Sine", 1);         //index starts at 1 for combobox
    oscMenu.addItem("Saw", 2);
    oscMenu.addItem("Square", 3);
    oscMenu.setJustificationType(Justification::centred);
    addAndMakeVisible(&oscMenu);
    oscMenu.addListener(this);

    waveSelection = new AudioProcessorValueTreeState::ComboBoxAttachment(processor.tree, "wavetype", oscMenu);
}

Oscillator::~Oscillator()
{
}

void Oscillator::paint (Graphics& g)
{
    juce::Rectangle<int> titleArea(0, 10, getWidth(), 20);

    g.fillAll(Colours::grey);
    g.setColour(Colours::white);
    g.drawText("Oscillator One", titleArea, Justification::centredTop);

    juce::Rectangle<float> area(25, 25, 150, 150);

    g.setColour(Colours::darkgreen);
    g.drawRoundedRectangle(area, 20.0f, 2.0f);


}

void Oscillator::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..

    juce:Rectangle<int> area = getLocalBounds().reduced(40);
    oscMenu.setBounds(area.removeFromTop(20));



}

void Oscillator::comboBoxChanged(ComboBox* box) 
{

}