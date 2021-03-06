# EKA2L1 [![Status](https://ci.appveyor.com/api/projects/status/umc5b97pwpyexh6q/branch/master?svg=true)](https://ci.appveyor.com/project/bentokun/eka2l1/branch/master)
- Best Symbian OS emulator to install and run malware. You can print things too!

<p align="center">
<img src="https://raw.githubusercontent.com/bentokun/EKA2L1/master/screenshots/result.png">
</p>

- Requirements:
    * 64 bit OS, 2 GB of RAM
    * At least OpenGL 3.2 is supported
    * A Symbian ROM. Currently, only Symbian 9.x is supported, and no drawing (AKN - Symbian GUI libraries, and GLES), is implemented yet.
 Only console app works
    
- Artifacts:
    * Artifacts for Windows is provided through CI. Click the status badge to get to EKA2L1's Appveyor CI
    
- Building:
    * Update all submodules: git submodule update --init --recursive
    * Using CMakeList in the root directory to generate solution/makefile. Make sure to turn off BUILD_TOOLS (tools are broken)
    * Building GUI using Lazarus 1.8.4. Must be FPC x86-64 and Lazarus 64 bit
    * Make sure to have the unicorn.dll related and eka2l1_api.dll in your executable / system directory if you want to run the GUI (because the GUI uses external functions from C++)

- For contributor:
   * You can starts by compiling the core and console and fixing warnings (or comment typos ;)) to get use to the code base.
   * You should learn some basic Symbian C++ (Active objects, Thread, Sync things, etc..) before getting in implementing HLE functions.
   * If you don't want to develop the core, you can contribute to the GUI. Either Lazarus (Pascal) or Qt (C++). I prefer Lazarus, but QT
 will make things easier

- Information and contact
    * You can contact me through Discord channel [here](https://discord.gg/5Bm5SJ9)
    
- Support
    * You can contribute to the codebase by submitting the PR. Please visit the wiki to know about the coding convention first ;)
    * You can also support me on [Patreon](https://www.patreon.com/fewdspuck)
