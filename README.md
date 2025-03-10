# Sharp Vehicle
    
"Sharp Vehicle" is a comprehensive application that demonstrates the capabilities of autonomous vehicle control in a simulated environment. The project combines a graphics component implemented using OpenGL with a neural network based on the DQN algorithm, developed using LibTorch for C++ and accelerated through CUDA. Additionally, the project integrates extra components such as input handling via Powershell and the use of auxiliary libraries for managing configurations, timers, and visual effects.

## Main Components

- **Graphics System:**  
  Utilizes OpenGL for rendering a 3D scene that includes vehicle models, road infrastructure, and environmental objects. It configures depth, blending, multisampling, and renders a skybox to create a realistic visual environment.

- **Neural Network and DQN:**  
  Implements the Deep Q-Learning (DQN) algorithm for autonomous control. The neural network, built with LibTorch, is trained on simulated data to provide intelligent vehicle behavior. The project includes components for model training, executing test steps, and saving training results.

- **Configuration and Integration:**  
  Reads and processes configuration files that allow flexible setting of window parameters, camera settings, collision models, and other subsystems. Libraries for configuration file management are used to easily modify project parameters without recompilation.

- **User Interface and Control:**  
  Implements a graphical user interface (GUI) for displaying simulation status information, as well as keyboard input handling for controlling different operational modes (e.g., switching between neural network training mode and manual vehicle control).

- **Architecture and Code Structure:**  
  The project code is organized using a modular approach:
  - **Libraries and Header Files:** For handling graphics, camera, timers, configurations, vehicle model, and collisions.
  - **Neural Network:** Modules for DQN training, managing training state, interfacing with the replay-buffer, and updating parameters.
  - **Main Function:** The core application loop that processes window events, updates camera and vehicle state, and performs neural network training.

## Build and Run

### Prerequisites

- **Graphics Component:**
  - Git, Powershell
  - OpenGL

- **Neural Network Component:**
  - CUDA (approximately 3.5 GB; tested version 12.2.1_536.67 on Windows 11)
  - cuDNN (approximately 700 MB; version 8.9.3.28 for CUDA 12 on Windows 11)
  - NVIDIA Nsight Graphics (approximately 1 GB; version 2023.2.1.23178 on Windows 11)
  - LibTorch for C++ (approximately 3 GB; tested DEBUG version 2.0.1 for CUDA 11.8 on Windows 11)
  - **Note:** Copy the files from  
    `C:\Program Files\NVIDIA GPU Computing Toolkit\CUDA\<version>\extras\visual_studio_integration\MSBuildExtensions`  
    to  
    `C:\Program Files (x86)\Microsoft Visual Studio\<version>\<product>\MSBuild\Microsoft\VC\<version>\BuildCustomizations`  
    (where `<product>` corresponds to your Visual Studio version: BuildTools, Enterprise, Community, etc.)

### Installation Instructions

1. **Clone the Repository:**
   ```bash
   git clone https://github.com/svgbogdnn/... .git
   cd ./...
   git submodule update --init --recursive
   ```

2. **Build the Project:**
   
   Run the build script:
   ```bash
   ./run.ps1
   ```

3. **Run the Executable:**
   
   After successful build, run the produced executable:
   ```bash
   SmartCarMain.exe <path_to_config_file>
   ```
   where `<path_to_config_file>` is the path to the configuration file.

'weighs quite a bit in size - small warning

Useful resources:
- [LibTorch RL Implementation](#)
- [DQN Theory](#)
- [DQN Basics](#)
- [DQN for Continuous Control Tasks](#)
