#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"

class IrloaderAudioProcessorEditor  : public AudioProcessorEditor, 
        private FilenameComponentListener
{
public:
    IrloaderAudioProcessorEditor (IrloaderAudioProcessor&);
    ~IrloaderAudioProcessorEditor();

    void paint (Graphics&) override;
    void resized() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    IrloaderAudioProcessor& processor;
    
    std::unique_ptr<FilenameComponent> fileComp;
    void filenameComponentChanged (FilenameComponent *f) override;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (IrloaderAudioProcessorEditor)
};
