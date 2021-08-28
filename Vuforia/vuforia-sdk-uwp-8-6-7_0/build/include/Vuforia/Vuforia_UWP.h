/*===============================================================================
Copyright (c) 2019 PTC Inc. All Rights Reserved.

Vuforia is a trademark of PTC Inc., registered in the United States and other
countries.

@file 
    Vuforia_UWP.h

@brief
    Header file for global Vuforia methods that are UWP specific.
===============================================================================*/

#ifndef _VUFORIA_UWP_H_
#define _VUFORIA_UWP_H_

// Include files
#include <Vuforia/System.h>

namespace Vuforia
{

/// Set Vuforia initialization parameters
/**
 * <b>UWP:</b> Call this function before calling Vuforia::init().
 *
 * See the "Lifecycle of a Vuforia app" section on the main %Vuforia
 * reference page for more information. \ref Lifecycle "Lifecycle of a Vuforia app"
 *
 * \param key Your %Vuforia license key.
 */
void VUFORIA_API setInitParameters(const char* key);

/// Display orientation types.
enum DISPLAY_ORIENTATION {
    NONE                  = 0,          ///< No display orientation is specified.

    LANDSCAPE             = 1,          ///< Specifies that the display is oriented in landscape mode 
                                        /// where the width of the display viewing area is greater than the height.

    PORTRAIT              = 2,          ///< Specifies that the display rotated 90 degrees in the clockwise direction 
                                        ///< to orient the display in portrait mode where the height of the display 
                                        ///< viewing area is greater than the width.

    LANDSCAPE_FLIPPED     = 4,          ///< Specifies that the display rotated another 90 degrees in the clockwise 
                                        ///< direction (to equal 180 degrees) to orient the display in landscape mode 
                                        ///< where the width of the display viewing area is greater than the height. 
                                        ///< This landscape mode is flipped 180 degrees from the Landscape mode.

    PORTRAIT_FLIPPED     = 8            ///< Specifies that the display rotated another 90 degrees in the clockwise 
                                        ///< direction (to equal 270 degrees) to orient the display in portrait mode 
                                        ///< where the height of the display viewing area is greater than the width. 
                                        ///< This portrait mode is flipped 180 degrees from the Portrait mode.
};

#ifdef __cplusplus_winrt
/// Utility method to convert display orientation type.
/**
 *<b>UWP:</b> Call to convert display orientation types.
 * 
 * \param orientation The orientatin of the screen to be converted to 
 * a DISPLAY_ORIENTATION value.
 * \returns the converted DISPLAY_ORIENTATION value.
 */
inline
DISPLAY_ORIENTATION VUFORIA_API toVuforiaDisplayOrientation(Windows::Graphics::Display::DisplayOrientations orientation)
{
    switch(orientation)
    {
        case Windows::Graphics::Display::DisplayOrientations::None:
            return Vuforia::DISPLAY_ORIENTATION::NONE;
        case Windows::Graphics::Display::DisplayOrientations::Landscape:
            return Vuforia::DISPLAY_ORIENTATION::LANDSCAPE;
        case Windows::Graphics::Display::DisplayOrientations::Portrait:
            return Vuforia::DISPLAY_ORIENTATION::PORTRAIT;
        case Windows::Graphics::Display::DisplayOrientations::LandscapeFlipped:
            return Vuforia::DISPLAY_ORIENTATION::LANDSCAPE_FLIPPED;
        case Windows::Graphics::Display::DisplayOrientations::PortraitFlipped:
            return Vuforia::DISPLAY_ORIENTATION::PORTRAIT_FLIPPED;
        default:
            return Vuforia::DISPLAY_ORIENTATION::NONE;
    }
}
#endif

/// Set the current screen orientation.
/**
 * <b>UWP:</b> Call to set any rotation on the %Vuforia rendered video background
 * and augmentation projection matrices to compensate for your application's
 * auto-rotation behaviour.
 *
 * The value specified is used internally by %Vuforia to adapt rendering and
 * tracking to the current screen orientation.
 *
 * This method should be called from the call-back registered with
 * DisplayInformation->OrientationChanged.
 *
 * Refer to the sample apps for full details.
 *
 * \param orientation The orientation of the screen.
 */
void VUFORIA_API setCurrentOrientation(DISPLAY_ORIENTATION orientation);

/// Set the app coordinate system.
/**
 * <b>UWP (Holographic):</b> Call to set the app coordinate system for Windows
 * Holographic applications. Call after Vuforia::init() but before the camera
 * is started.
 *
 * \param appSpecifiedCS A pointer to an ISpatialCoordinateSystem object representing
 * your app's coordinate system.
 */
bool VUFORIA_API setHolographicAppCS(void* appSpecifiedCS);

} // namespace Vuforia

#endif //_VUFORIA_UWP_H_
