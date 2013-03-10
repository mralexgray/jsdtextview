//
//  AppDelegate.m
//  LineNumberNoWrapTextDemo
//
//  Created by Jim Derry on Sat Mar 01 2003.
//  Copyright (c) 2003 __MyCompanyName__. All rights reserved.
//

#import "AppDelegate.h"


@implementation AppDelegate

-(IBAction)checkWrap:(id)sender {
    [textView setWordWrap:([sender state] == NSOnState)];
}



-(IBAction)checkLine:(id)sender {
    [textView setShowLineNumbers:([sender state] == NSOnState)];

}


@end
