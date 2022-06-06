# qt-enedis-tic

## Generalities

### Introduction

This Qt software is a simple application to visualize "télé-information client"
data from Enedis power meters's information output.

It is split into several modules, so the decoding lib can be used independently
from the UI.


### Disclaimer

THIS PROGRAM IS PROVIDED AS-IS, WITHOUT ANY WARRANTY OF ANY SORT.

Users are responsible for their own actions, don't do anything if you're not
qualified, or unsure about what you're doing!


### Harware requirements

For this program to work, you will need a hardware interface capable of
converting the signal from the power meter's information plug to a standard
serial interface.

You can either build your own or buy it on the Internet from a variety of
sellers.


## How to build

First dowload the source code of this repository, then open a terminal in the
root folder:
1.  Run `qmake`
    ~~~~~{sh}
    qmake

    # or if you want to enable debugging:
    qmake CONFIG+=debug CONFIG+=qml_debug
    ~~~~~

2.  Build the project using make
    ~~~~~{sh}
    $ make -j4
    ~~~~~


Then the generated binary is available under `out/` in each sub-directory.

+ Optional: Install it on your system
  ~~~~~{sh}
  $ sudo make install
  # Then you will probably need to call...
  $ sudo ldconfig
  #...to update shared library bindings, otherwise it won't be found at runtime.
  ~~~~~
+ Uninstall:
  ~~~~~{sh}
  $ sudo make uninstall
  ~~~~~


## Usage

1. Connect your serial interface from the power meter to the computer.
2. Start the program.
   + From the local build directory:
     ~~~~~{sh}
     $ LD_LIBRARY_PATH=enedisTIC/out/ ./enedisTIC-ui/out/enedisTIC-ui
     ~~~~~
   + From the system install:
     ~~~~~{sh}
     $ enedisTIC-ui
     ~~~~~
3. In the toolbar at the top of the screen, choose the serial port on which the
power meter is connected, choose the TIC mode, then click the `Open`
push button.

If frames are received, the interface will be updated in real-time and a counter
on the bottom right status bar will show how many frames have been received.
