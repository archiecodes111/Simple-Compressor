#pragma once

#include "PluginProcessor.h"
using namespace juce;
using namespace std;

//==============================================================================
class AudioPluginAudioProcessorEditor final : public juce::AudioProcessorEditor {
  public:
	explicit AudioPluginAudioProcessorEditor(AudioPluginAudioProcessor &);
	~AudioPluginAudioProcessorEditor() override;

	//==============================================================================
	void paint(juce::Graphics &) override;
	void resized() override;

  private:
	Slider thresholdSlider;
	Slider ratioSlider;
	Slider attackSlider;
	Slider releaseSlider;
	Slider makeupSlider;

	using SliderAttachment = AudioProcessorValueTreeState::SliderAttachment;

	unique_ptr<SliderAttachment> thresholdAttachment;
	unique_ptr<SliderAttachment> ratioAttachment;
	unique_ptr<SliderAttachment> attackAttachment;
	unique_ptr<SliderAttachment> releaseAttachment;
	unique_ptr<SliderAttachment> makeupAttachment;

	Label thresholdLabel{"thresholdLabel", "Threshold"};
	Label ratioLabel{"ratioLabel", "Ratio"};
	Label attackLabel{"attackLabel", "Attack"};
	Label releaseLabel{"releaseLabel", "Release"};
	Label makeupLabel{"makeupLabel", "Makeup"};

	// This reference is provided as a quick way for your editor to
	// access the processor object that created it.
	AudioPluginAudioProcessor &processorRef;

	JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(
	    AudioPluginAudioProcessorEditor)
};
