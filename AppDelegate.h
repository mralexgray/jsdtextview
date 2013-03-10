//
//  AppDelegate.h
//  LineNumberNoWrapTextDemo
//
//  Created by Jim Derry on Sat Mar 01 2003.
//  Copyright (c) 2003 __MyCompanyName__. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "JSDTextView.h"

@interface AppDelegate : NSObject {
    IBOutlet JSDTextView *textView;
}

-(IBAction)checkWrap:(id)sender;	// handle checkbox button
-(IBAction)checkLine:(id)sender;	// handle line number button

@end
