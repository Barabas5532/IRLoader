cmake_minimum_required(VERSION 3.15)
project(IRLoader VERSION 0.0.1)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_subdirectory(JUCE)

juce_add_plugin(IRLoader
    COMPANY_NAME "Barabas Raffai"
    PLUGIN_MANUFACTURER_CODE BaRa
    PLUGIN_CODE IRLD
    FORMATS VST3 Standalone
    PRODUCT_NAME "IR Loader")

juce_generate_juce_header(IRLoader)

target_sources(IRLoader
    PRIVATE
        Source/PluginEditor.cpp
        Source/PluginProcessor.cpp)

target_include_directories(IRLoader
    PRIVATE
        Source)

target_compile_definitions(IRLoader
    PUBLIC
        JUCE_DISPLAY_SPLASH_SCREEN=0
        JUCE_WEB_BROWSER=0
        JUCE_USE_CURL=0
        JUCE_VST3_CAN_REPLACE_VST2=0)

target_link_libraries(IRLoader
    PRIVATE
        juce::juce_audio_utils
        juce::juce_dsp
    PUBLIC
        juce::juce_recommended_config_flags
        juce::juce_recommended_lto_flags
        juce::juce_recommended_warning_flags)
