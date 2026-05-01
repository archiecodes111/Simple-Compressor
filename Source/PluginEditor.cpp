#include "PluginEditor.h"
#include "PluginProcessor.h"

//==============================================================================
AudioPluginAudioProcessorEditor::AudioPluginAudioProcessorEditor(
    AudioPluginAudioProcessor &p)
    : AudioProcessorEditor(&p), processorRef(p) {
	juce::ignoreUnused(processorRef);
	// Make sure that before the constructor has finished, you've set the
	// editor's size to whatever you need it to be.
	setSize(700, 300);

	addAndMakeVisible(thresholdSlider);
	addAndMakeVisible(ratioSlider);
	addAndMakeVisible(attackSlider);
	addAndMakeVisible(releaseSlider);
	addAndMakeVisible(makeupSlider);

	thresholdSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
	ratioSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
	attackSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
	releaseSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);
	makeupSlider.setSliderStyle(juce::Slider::RotaryHorizontalVerticalDrag);

	thresholdSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 60, 20);
	ratioSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 60, 20);
	attackSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 60, 20);
	releaseSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 60, 20);
	makeupSlider.setTextBoxStyle(juce::Slider::TextBoxBelow, false, 60, 20);

	thresholdAttachment = std::make_unique<SliderAttachment>(
	    processorRef.apvts, "threshold", thresholdSlider);

	ratioAttachment = std::make_unique<SliderAttachment>(
	    processorRef.apvts, "ratio", ratioSlider);

	attackAttachment = std::make_unique<SliderAttachment>(
	    processorRef.apvts, "attack", attackSlider);

	releaseAttachment = std::make_unique<SliderAttachment>(
	    processorRef.apvts, "release", releaseSlider);

	makeupAttachment = std::make_unique<SliderAttachment>(
	    processorRef.apvts, "makeup", makeupSlider);

	addAndMakeVisible(thresholdLabel);
	addAndMakeVisible(ratioLabel);
	addAndMakeVisible(attackLabel);
	addAndMakeVisible(releaseLabel);
	addAndMakeVisible(makeupLabel);

	thresholdLabel.setJustificationType(juce::Justification::centred);
	ratioLabel.setJustificationType(juce::Justification::centred);
	attackLabel.setJustificationType(juce::Justification::centred);
	releaseLabel.setJustificationType(juce::Justification::centred);
	makeupLabel.setJustificationType(juce::Justification::centred);
}

AudioPluginAudioProcessorEditor::~AudioPluginAudioProcessorEditor() {}

//==============================================================================
void AudioPluginAudioProcessorEditor::paint(juce::Graphics &g) {
	// (Our component is opaque, so we must completely fill the background with
	// a solid colour)
	g.fillAll(
	    getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));

	g.setColour(juce::Colours::white);
	g.setFont(15.0f);
	// g.drawFittedText("Hello World!", getLocalBounds(),
	//                  juce::Justification::centred, 1);
}

void AudioPluginAudioProcessorEditor::resized() {
	// This is generally where you'll want to lay out the positions of any
	// subcomponents in your editor..
	auto area = getLocalBounds().reduced(20);

	auto sectionWidth = area.getWidth() / 5;

	auto layoutSection = [&](juce::Slider &slider, juce::Label &label) {
		auto section = area.removeFromLeft(sectionWidth);

		auto labelArea = section.removeFromTop(25);
		label.setBounds(labelArea);

		slider.setBounds(section.reduced(10));
	};

	layoutSection(thresholdSlider, thresholdLabel);
	layoutSection(ratioSlider, ratioLabel);
	layoutSection(attackSlider, attackLabel);
	layoutSection(releaseSlider, releaseLabel);
	layoutSection(makeupSlider, makeupLabel);
}
