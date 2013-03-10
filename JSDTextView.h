/***************************************************************************************
    JSDTextView.h

    Modify NSTextView for a single, special purpose. We will:
        o non-wrapping text with a line counter to the left.
        o self contained (hence multiple classes in this header)
        
    We will:
        o hand-build an NSScrollView, NSTextView, NSLayoutManager, NSTextContainer,
          and NSTextStorage for textView, and add a JSDNumberView for numberView
        o allow turning wrapping of text to YES or NO.
        o allow turning line number counting to YES or NO.
        
    I'd like to give especial thanks to Koen van der Drift <kvddrift@earthlink.net>
    for the means to implement the line numbering in the NSTextView subclass!
 ***************************************************************************************/

#import <Cocoa/Cocoa.h>

@class JSDTextView;

//========================================================================================================
// JSDTextViewSub -- this NSTextView subclass overrides drawRect: in order to force it to
//		    update the associated NSView in addition to the inherited method.
//========================================================================================================
@interface JSDTextViewSub : NSTextView {
    NSView *_friendView;
}
-(NSView *)friendView;				// return the associated view
-(void)setFriendView:(NSView *)theView;		// set the associated view
@end


//========================================================================================================
// JSDNumberView -- this NSView subclass draws its own line numbers in drawRect: based on the associated
//                  Text view in _owner. Provide accessor methods for _textView.
//========================================================================================================
@interface JSDNumberView : NSView {
    JSDTextView *_owner;
    BOOL _showLineNumbers;		// show line numbers or not? Default YES    
}
-(JSDTextView *)owner;			// return the associated JSDTextView
-(void)setOwner:(JSDTextView *)theView;	// set the associate JSDTextView

-(BOOL)showLineNumbers;			// returns whether we're showing line numbers or not.
-(void)setShowLineNumbers:(BOOL)value;	// set whether we're showing line numbers or not.

@end

//========================================================================================================
// JSDTextView -- this NSTextView is just a REGULAR NSView subclass that does everything relates to a
//		  textview internally. The NSTextView is exposed so that all of the regular messages
//		  can be sent to it for setup without having to duplicate them in this wrapper.        
//========================================================================================================
@interface JSDTextView : NSView {
    NSScrollView *_scrollView;		// the enclosing scrollview.
    NSLayoutManager *_layoutManager;	// the layout manager
    NSTextContainer *_textContainer;	// the text container.
    JSDTextViewSub *_textView;		// the text view
    JSDNumberView *_numberView;		// the number view
    
    BOOL _wordWrap;			// current word-wrap state.
    
    IBOutlet id delegate;		// expose the NSTextView's delegate
}

-(NSScrollView *)scrollView;		// expose the enclosing scrollview.
-(NSLayoutManager *)layoutManager;	// expose the layout manager
-(NSTextContainer *)textContainer;	// expose the text container.
-(NSTextView *)textView;		// expose the text view
-(JSDNumberView *)numberView;		// expose the number view

-(NSString *)string;			// convenience method to get the NSTextView string
-(void)setString:(NSString *)aString;	// convenience method to set the NSTextView string

- (void)setDelegate:(id)anObject;	// convenience to allow setting of TextView delegate in IB
- (id)delegate;				// complement to above

-(BOOL)showLineNumbers;			// get this from the numberview that we're hosting.
-(void)setShowLineNumbers:(BOOL)value;	// set this in the numberview that we're hosting.

-(BOOL)wordWrap;			// returns the word-wrap state
-(void)setWordWrap:(BOOL)value;		// sets the word-wrap state.

@end
