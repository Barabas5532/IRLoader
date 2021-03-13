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

#include "PluginProcessor.h"
#include "PluginEditor.h"

IrloaderAudioProcessorEditor::IrloaderAudioProcessorEditor (IrloaderAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{

    fileComp.reset (new FilenameComponent ( "fileComp",
                {},
                false,
                false,
                false,
                "*.wav",
                {},
                "Select an IR!"));

    addAndMakeVisible (fileComp.get());
    fileComp->addListener (this);
    
    // Make sure that before the constructor has finished, you've set the
    // editor's size to whatever you need it to be.
    setSize (400, 90);
}

IrloaderAudioProcessorEditor::~IrloaderAudioProcessorEditor()
{
}

void IrloaderAudioProcessorEditor::paint (Graphics& g)
{
    // (Our component is opaque, so we must completely fill the background with a solid colour)
    g.fillAll (getLookAndFeel().findColour (ResizableWindow::backgroundColourId));

    g.setColour (Colours::white);
    g.setFont (15.0f);
    g.drawFittedText("IR Loader", 0, 0, getWidth(), 30, Justification::centred,
            1);
}

void IrloaderAudioProcessorEditor::resized()
{
    // This is generally where you'll want to lay out the positions of any
    // subcomponents in your editor..
    fileComp->setBounds(20, 30, getWidth() - 40, 40);
}

void IrloaderAudioProcessorEditor::filenameComponentChanged(FilenameComponent* f) 
{
    processor.convolution.loadImpulseResponse(f->getCurrentFile(), dsp::Convolution::Stereo::no, dsp::Convolution::Trim::no, 0);
}
