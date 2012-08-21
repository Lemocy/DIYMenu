//
//  DIYMenu.h
//  DIYMenu
//
//  Created by Jonathan Beilin on 8/13/12.
//  Copyright (c) 2012 DIY. All rights reserved.
//
//  Thanks to Sam Vermette for sharing good ideas and clean
//  code for managing a singleton overlay view in SVProgressHUD.

#import <UIKit/UIKit.h>

@class DIYMenuItem;

@protocol DIYMenuDelegate <NSObject>
@required
- (void)menuItemSelected:(NSString *)action;
@optional
- (void)menuActivated;
- (void)menuCancelled;
@end

@protocol DIYMenuItemDelegate <NSObject>
- (void)diyMenuAction:(NSString *)action;
@end

@interface DIYMenu : UIView <DIYMenuItemDelegate> {
@private
    NSMutableArray              *_menuItems;
    NSMutableArray              *_titleButtons;
    BOOL                        _isActivated;
    DIYMenuItem                 *_titleBar;
    NSObject<DIYMenuDelegate>   *_delegate;
    UIWindow                    *_overlayWindow;
    UIView                      *_blockingView;
}

//
// Class methods
//

// Setup
+ (void)setDelegate:(NSObject<DIYMenuDelegate> *)delegate;

+ (void)setTitle:(NSString *)title withDismissIcon:(UIImage *)dismissImage withColor:(UIColor *)color withFont:(UIFont *)font;
+ (void)addTitleButton:(NSString *)name withIcon:(UIImage *)image;
+ (void)addMenuItem:(NSString *)name withIcon:(UIImage *)image withColor:(UIColor *)color withFont:(UIFont *)font;

// Usage
+ (void)show;
+ (void)dismiss;
+ (BOOL)isActivated;

//

@end