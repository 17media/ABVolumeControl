//
//  ABVolumeControl.h
//  Pods
//
//  Created by Andrew Boryk on 2/11/17.
//
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <MediaPlayer/MediaPlayer.h>
#import <QuartzCore/QuartzCore.h>

typedef NS_ENUM(NSInteger, ABVolumeControlTheme) {
    ABVolumeControlLightTheme,
    ABVolumeControlDarkTheme,
};

typedef NS_ENUM(NSInteger, ABVolumeControlStyle) {
    ABVolumeControlStyleNone,
    ABVolumeControlStyleMinimal,
    ABVolumeControlStyleStatusBar,
    ABVolumeControlStyleCustom,
};

@protocol ABVolumeControlDelegate;

@interface ABVolumeControl : NSObject

/// Delegate for ABVolumeControl
@property (weak, nonatomic) id<ABVolumeControlDelegate> volumeDelegate;

/// Determines whether volume bar should be shown
@property BOOL dontShowVolumeBar;

/// Background for volume bar
@property (strong, nonatomic) UIView *volumeBackground;

/// Bar which shows volume level
@property (strong, nonatomic) UIView *volumeBar;

/// View which handles volume change
@property (strong, nonatomic) MPVolumeView *mpVolumeView;

/// Slider which records the user's volume level
@property (strong, nonatomic) UISlider *volumeSlider;

// Timer that when selector is performed, hides volumeBar
@property (strong, nonatomic) NSTimer *volumeTimer;

/// The default light color for the volume bar
@property (strong, nonatomic) UIColor *defaultLightColor;

/// The default dark color for the volume bar
@property (strong, nonatomic) UIColor *defaultDarkColor;

/// Theme for the ABVolumeControl (Light or Dark)
@property (nonatomic) ABVolumeControlTheme controlTheme;

/// Style of ABVolumeControl desired for the user's interface
@property (nonatomic) ABVolumeControlStyle volumeControlStyle;

/// Shared Manager for Volume Manager
+ (id)sharedManager;

/// Hides volume bar for 2.5 seconds
- (void) dontShowVolumebar;

/// Shows volume bar
- (void) showVolumeBar;

/// Updates color for volumebar
- (void) updateVolumeBarColor;

/// Setting the volume for the ABVolumeControl and the user's device
+ (void) setVolumeLevel:(float)volumeLevel;

@end

@protocol ABVolumeControlDelegate <NSObject>

@optional

/// Volume did change to a different percentage
- (void)control:(ABVolumeControl *)control didChangeVolume:(CGFloat)volumePercentage;

@end
