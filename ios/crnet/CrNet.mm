// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#import "ios/crnet/CrNet.h"

#include "base/logging.h"
#import "ios/net/crn_http_protocol_handler.h"
#import "ios/crnet/crnet_environment.h"

static CrNetEnvironment* g_chrome_net = NULL;

static BOOL g_spdy_enabled = YES;
static BOOL g_quic_enabled = NO;
static NSString *g_user_agent = nil;
static double g_alternate_protocol_threshold = 1.0;
static RequestFilterBlock g_request_filter_block = nil;

@implementation CrNet

+ (void)setSpdyEnabled:(BOOL)spdyEnabled {
  g_spdy_enabled = spdyEnabled;
}

+ (void)setQuicEnabled:(BOOL)quicEnabled {
  g_quic_enabled = quicEnabled;
}

+ (void)setPartialUserAgent:(NSString *)userAgent {
  g_user_agent = userAgent;
}

+ (void)setAlternateProtocolThreshold:(double)alternateProtocolThreshold {
  g_alternate_protocol_threshold = alternateProtocolThreshold;
}

+ (void)installInternal {
  CrNetEnvironment::Initialize();
  std::string partial_user_agent =
      [g_user_agent cStringUsingEncoding:NSASCIIStringEncoding];
  g_chrome_net = new CrNetEnvironment(partial_user_agent);

  g_chrome_net->set_spdy_enabled(g_spdy_enabled);
  g_chrome_net->set_quic_enabled(g_quic_enabled);
  g_chrome_net->set_alternate_protocol_threshold(
      g_alternate_protocol_threshold);

  g_chrome_net->Install();
  g_chrome_net->SetHTTPProtocolHandlerRegistered(true);
  g_chrome_net->SetRequestFilterBlock(g_request_filter_block);
}

+ (void)install {
  static dispatch_once_t onceToken;
  dispatch_once(&onceToken, ^{
      [self installInternal];
  });
}

+ (void)installIntoSessionConfiguration:(NSURLSessionConfiguration*)config {
  g_chrome_net->InstallIntoSessionConfiguration(config);
}

+ (void)installWithPartialUserAgent:(NSString *)partialUserAgent {
  [self setPartialUserAgent:partialUserAgent];
  [self install];
}

+ (void)installWithPartialUserAgent:(NSString *)partialUserAgent
           enableDataReductionProxy:(BOOL)enableDataReductionProxy {
  LOG(ERROR) << "enableDataReductionProxy is no longer respected. The "
      << "functionality has been removed from CrNet.";

  [self setPartialUserAgent:partialUserAgent];
  [self install];
}

+ (void)installWithPartialUserAgent:(NSString *)partialUserAgent
             withRequestFilterBlock:(RequestFilterBlock)requestFilterBlock {
  [self setPartialUserAgent:partialUserAgent];
  [self setRequestFilterBlock:requestFilterBlock];
  [self install];
}

+ (void)setRequestFilterBlock:(RequestFilterBlock)block {
  if (g_chrome_net)
    g_chrome_net->SetRequestFilterBlock(block);
  else
    g_request_filter_block = block;
}

+ (void)uninstall {
  if (g_chrome_net) {
    g_chrome_net->SetHTTPProtocolHandlerRegistered(false);
  }
}

+ (void)startNetLogToFile:(NSString *)fileName logBytes:(BOOL)logBytes {
  if (g_chrome_net && [fileName length]) {
    g_chrome_net->StartNetLog([fileName UTF8String], logBytes);
  }
}

+ (void)stopNetLog {
  if (g_chrome_net) {
    return g_chrome_net->StopNetLog();
  }
}

+ (NSString *)userAgent {
  if (!g_chrome_net) {
    return nil;
  }

  std::string user_agent = g_chrome_net->user_agent();
  return [NSString stringWithCString:user_agent.c_str()
                            encoding:[NSString defaultCStringEncoding]];
}

+ (void)closeAllSpdySessions {
  if (g_chrome_net) {
    return g_chrome_net->CloseAllSpdySessions();
  }
}

+ (void)clearCacheWithCompletionCallback:(ClearCacheCallback)clearCacheCallback {
  if (g_chrome_net) {
    g_chrome_net->ClearCache(clearCacheCallback);
  }
}

@end
