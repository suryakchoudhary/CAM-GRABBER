# An exercise in application latency

In typical AI/Robotics applications images from a camera are used for techniques
like object-detection, mapping, obstacle avoidance, etc. In such applications,
it is necessary that each of the modules is able to free the common compute
resources as soon as possible. It is also necessary that the common variables
shared between the modules are appropriately access-protected.

The application in this repository is an over-simplification of the same and is
intended to validate some basic coding skills to improve latency.

 ## Description of the application
 The application in this repository consists of three modules

### Cam
This module is responsible for grabbing images from an onboard camera. This
module would return an image in the form of an `std::vector<unsigned int>`. This
module should be able to grab images at `20 fps (50 ms)`.

The `run(...)` function is to be called for the module to grab the image and
return it. Called in isolation, it should be able to run every `50ms`.

### AI
This module analyses the image and would run some AI routines on it. To emulate
the computation load, the `run(...)` function would sleep for `200ms`.

### Navigation
This module would use the image for navigation, mapping and obstacle avoidance.
To emulate the computation load, the `run(...)` function would sleep for
`100ms`.

## Building the application

```
$ mkdir build && cd build
$ cmake ..
$ make
```

## Running the application

```
$ cd build
$ ./cam_grabber
```

## Issues in the application
Due to a badly written code, the application fails to do what it is supposed to
do as per the above sections.

If you run the application as-is, below is the output that you should expect

```
[Nav]: Time since last execution: 357.548 ms
[AI ]: Time since last execution: 353.589 ms
[Cam]: Time since last execution: 353.485 ms
[Nav]: Time since last execution: 354.102 ms
[AI ]: Time since last execution: 354.161 ms
[Cam]: Time since last execution: 354.172 ms
...
...
```

This is an issue because the camera module is no longer able to capture images
at the required `20fps` and the navigation module is not able to run at its
required `100ms` rate. This will lead to a very sluggish application.

## Assignment
Your job is to refactor certain parts of the code such that the expected output
looks like below.

```
[Cam]: Time since last execution: 5x.xxx ms
[Cam]: Time since last execution: 5x.xxx ms
[Nav]: Time since last execution: 10x.xxx ms
[Cam]: Time since last execution: 5x.xxx ms
[Cam]: Time since last execution: 5x.xxx ms
[Nav]: Time since last execution: 10x.xxx ms
[AI ]: Time since last execution: 20x.xxx ms
...
...
```

During the course of this task, you might also notice that there are some other
inefficiencies in the functions as well. You can also make a note of those and
fix those inefficiencies.

# Ground Rules
In order to start working on the assignment, you need to [fork this
project](https://gitlab.com/miko.ai/cam-grabber/-/forks/new) to your personal
space. Once that is done, please make your project private and add @miko.ai to
your project as a _Reporter_.

For any queries, you can tag @miko.ai in any issues on your project.