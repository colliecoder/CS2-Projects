# bigint
A fun project to create a bigint class in C++. This was the culmination of several weeks of solid work and speed coding - a class made for class :point_up: :point_right: . 

## Usage
After you've downloaded the included .hpp and .cpp files you can include bigint in any code as long as you use:

```cpp
#include "bigint.hpp"
```

Be sure to make sure bigint.hpp and bigint.cpp are both accessible via the path to the current file you are working in. This may mean copying the files into the same folder as the code you are trying to include bigint with. 

Don't exceed a number more than 400 units long as the capacity of the array of integers that makes up bigint is only 400 at the moment. This should be plenty of space for most numbers. 

There are three ways to create a bigint:
1. As an empty bigint:
```cpp
bigint bi();
```

2. With an integer value:
```cpp
bigint bi = 42;
```

3. With a character value:
```cpp
bigint bi = "39089080980980980980";
```



## Background on bigint

So bigint is a class that utilizes an array of ints (or a char array if you're crazy and value the minimal amount of space saving that would give you). The need for bigint arises out of situations where you need to use a really large number (so large that it exceeds 2147483647 as a signed int). 2147483647 may seem like a big number but imagine you start working with integers so big they're taking up 200.... even, in the case of my code, up to 400 spaces. That's when you need... a very fancy array of ints. 

![big bigint meme](https://hugelolcdn.com/i/436172.jpg)



## Contribution
Since this was originally a school project I would prefer if people did not contribute to this project at the moment. I use github to store, maintain and showcase my code for bigint but it is a purely educational project - not a collaborative one. As such I have not included a license and maintain the copyrights of my personal code. Please feel free to download and explore this project at your own leisure as long as it is not being used for plagiarism or modified!

## The Future of bigint
My current plans for the future of bigint include going into the project to neaten it up and add more documentation. This was my first major experience with more advanced C++ projects and my first major project I consider to have "speed coded" so when I go back and look at it now its a little rough. I had just passed the hello world stage and really started to code when I made this. 

Making it dynamic may be in the future as well for a rainy day!
