# Simple-Compressor-Plugin

A simple real-time compressor plugin built with JUCE and C++.

This project was built as a learning-focused audio plugin exploring the fundamentals of dynamics processing, DSP, and plugin architecture.

## Features

* Real-time dynamic range compression
* Adjustable:

  * Threshold
  * Ratio
  * Attack
  * Release
  * Makeup Gain
* Custom GUI with rotary controls
* VST3 + Standalone targets
* Built using CMake
* DAW compatible

---

## DSP Concepts Used

This plugin implements core compressor concepts including:

* Envelope Following
* Attack/Release Smoothing
* Gain Reduction Calculation
* dB ↔ Linear Conversion
* Real-Time Audio Processing
* Parameter Management using APVTS

---

## Built With

* JUCE
* C++17
* CMake

---

## Plugin Controls

| Parameter   | Description                          |
| ----------- | ------------------------------------ |
| Threshold   | Level above which compression begins |
| Ratio       | Amount of compression applied        |
| Attack      | How quickly compression reacts       |
| Release     | How quickly compression recovers     |
| Makeup Gain | Output gain after compression        |

---

## Building the Project

### Requirements

* CMake
* C++17 compatible compiler
* JUCE submodule initialized

### Configure

```bash id="e8q5m1"
cmake -B build -DCMAKE_BUILD_TYPE=Release
```

### Build

```bash id="v7t2k4"
cmake --build build
```

---

## Plugin Formats

This project builds:

* VST3
* Standalone Application

---

## Project Structure

```text id="m3w9d2"
Source/
    PluginProcessor.cpp
    PluginProcessor.h
    PluginEditor.cpp
    PluginEditor.h

modules/
    JUCE/

CMakeLists.txt
```

---

## Current State

The plugin currently includes:

* Functional compression DSP
* Custom parameter-linked GUI
* Basic stereo support

Future improvements may include:

* Gain Reduction Meter
* Soft Knee Compression
* RMS Detection
* Stereo Linking
* Lookahead
* Custom LookAndFeel
* Oversampling

---

## License

This project is open-source and available under the MIT License.

---

## Author

Built by Archie DSP 🎛️
