/*
 *  This file is part of IR Loader.
 *  Copyright (C) 2019 - 2021  Barabas Raffai
 *
 *  IR Loader is free software: you can redistribute it and/or
 *  modify it under the terms of the GNU General Public License as
 *  published by the Free Software Foundation, either version 3 of the
 *  License, or (at your option) any later version.
 *
 *  IR Loader is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with IR Loader.  If not, see <https://www.gnu.org/licenses/>.
 */

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
