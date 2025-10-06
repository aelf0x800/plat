# Plat World Format
The world format utilised by the Plat engine is a custom one. It is sepcifically 
made for the sole purpose of designing a world for a platformer game.

## What it handles
* Platforms
* Background
* Foreground
* Player
* Enemies
* Textures

## The properties
### Background
The background property is quite simple. All it does is set the background of
the game.
```
##
## Here are some examples of how to use the background property.
##

# Simple static one layer background
Background
{
    Animated = No;
    
    # Properties such as "SlidingSpeed" and "SwappingSpeed" in this case will throw 
    # an error as they are not needed.

    Image = "picture.png"; # It is just image here because we only need one image.
}

# Sliding multi layer background
Background
{
    Animated = Sliding, Swapping; # This means that the texture(s) will be sliding 
                                  # across the screen in loop.
    
    SlidingSpeed = 1; # This is measured in pixels per millisecond.

    Images  # It is images here because we need more than one image due to more layers.
    {
        "pictureA1.jpg",
        "pictureB1.jpg",
        "pictureC1.jpg",
    }


# Sliding and swapping backgrounds
Background
{
    Animated = Sliding, Swapping; # This means that the texture(s) will be sliding 
                                  # across the screen in loop and that it will
                                  # also swap those sliding texture(s) out for
                                  # the ones defined.
    
    SlidingSpeed = 1; # This is measured in pixels per millisecond.
    SwappingSpeed = 100; # This is measured in swaps per millisecond.

    Images
    {
        # Each block represents a layer.
        # This is the back layer as it is at the top of the "Images" property.
        {
            "pictureA1.jpg",
            "pictureA2.jpg",
            "pictureA3.jpg"
        },
        {
            "pictureB1.jpg",
            "pictureB2.jpg",
            "pictureB3.jpg"
        },
        {
            "pictureC1.jpg",
            "pictureC2.jpg",
            "pictureC3.jpg"
        }
    }
}
```
