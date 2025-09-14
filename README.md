# ClasHStamP 2.0 Readme

# Prerequisites

## For Windows OS and Astah Pro
* Change-Vision Astah Professional (Version 8 or later)
* Visual Studio 2015 or later (C++ any edition, Commnity is OK)
* Java 8 SDK
    * Path to download: https://www.oracle.com/europe/java/technologies/javase/javase8u211-later-archive-downloads.html
    * The file should be downloaded is ```jdk-8u451-windows-x64.zip```
    * Unzip to a local folder, for example: ```C:\<YourPath>\jdk1.8.0_451```

# How to Generate C Code from a Sample Model
* Check out or Download this Github Repository to a local folder
https://github.com/ducyen/ClasHStamP_Online.git

For example: ```C:\<YourPath>\ClasHStamP_Online```
* Copy your Astah Professional folder to overwrite the ```C:\<YourPath>\ClasHStamP_Online\astah-pro``` folder like below </br>
![This is an alt text.](/doc/astah_copy.png "This is a sample image.")
* Start Command Prompt console and enter these commands:
    * Set Java 8 SDK path: ```>set PATH=C:\<YourPath>\jdk1.8.0_451\bin```
    * Change directory to ClasHStamP folder: ```>cd C:\<YourPath>\ClasHStamP_Online\```
    * Compile ClasHStamP GUI: ```>javac Main.java```
    * Start ClasHStamP GUI: ```>java Main``` </br> 
    And you will see a screen like this </br>
    ![This is an alt text.](/doc/clashstamp_gui.png "This is a sample image.")
* On the top-right panel, enter fields like this:</br>

| Field                 | Value                 |
| --------------------- |:---------------------:|
| Sample Name           | ```TypicalNotations```|
| Launch Diagram Editor | ```pro```             |
| Select Language       | ```C```               |

* Press ```Generate Code``` button
   * and wait until Output Window has shown ```"Code Generation Finished"```
* Use Visual C++. open this Solution here: </br>```C:\<YourPath>\ClasHStamP_Online\samples\TypicalNotations\TypicalNotations.sln```</br>
* On the Solution Explorer, set C project to be ```Set as Startup Project```
* Build and Run this C project, you will see a screen like this:</br>
    ![This is an alt text.](/doc/vs_run.png "This is a sample image.")

# How to Generate Test Cases a Sample Model
* On the Main window, press ```R``` key
    * and wait until the console has shown: ```Testcases successfully genereated!```
    * you will see the test cases file is generated here: ```C:\<YourPath>\ClasHStamP_Online\samples\TypicalNotations\testcases.csv```

## For Windows OS and Astah UML
T.B.D

## For Linux or Mac OS
T.B.D

# Limitations
* The Test Cases generation function doesn't work with Guard or ChoicePseudostate.
    * Work around: Replace this ChoicePseudostate by a JoinPseudostate, with one of the incomming transition comes from a region with states representing the above choice conditions.</br>
    For example, in this sample, I have created a substitution for `(CarOn) ---PWR_BTN[Gear==Parked]---> (CarOff)`.

# References
* Refer to this YouTube video for more details: https://youtu.be/wyrNfo1aYpg?si=2Yq5X2zFzfMIsATT


