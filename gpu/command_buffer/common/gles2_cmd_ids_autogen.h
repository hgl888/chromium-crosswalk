// Copyright 2014 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

// This file is auto-generated from
// gpu/command_buffer/build_gles2_cmd_buffer.py
// It's formatted by clang-format using chromium coding style:
//    clang-format -i -style=chromium filename
// DO NOT EDIT!

#ifndef GPU_COMMAND_BUFFER_COMMON_GLES2_CMD_IDS_AUTOGEN_H_
#define GPU_COMMAND_BUFFER_COMMON_GLES2_CMD_IDS_AUTOGEN_H_

#define GLES2_COMMAND_LIST(OP)                           \
  OP(ActiveTexture)                            /* 256 */ \
  OP(AttachShader)                             /* 257 */ \
  OP(BindAttribLocationBucket)                 /* 258 */ \
  OP(BindBuffer)                               /* 259 */ \
  OP(BindBufferBase)                           /* 260 */ \
  OP(BindBufferRange)                          /* 261 */ \
  OP(BindFramebuffer)                          /* 262 */ \
  OP(BindRenderbuffer)                         /* 263 */ \
  OP(BindSampler)                              /* 264 */ \
  OP(BindTexture)                              /* 265 */ \
  OP(BindTransformFeedback)                    /* 266 */ \
  OP(BlendColor)                               /* 267 */ \
  OP(BlendEquation)                            /* 268 */ \
  OP(BlendEquationSeparate)                    /* 269 */ \
  OP(BlendFunc)                                /* 270 */ \
  OP(BlendFuncSeparate)                        /* 271 */ \
  OP(BufferData)                               /* 272 */ \
  OP(BufferSubData)                            /* 273 */ \
  OP(CheckFramebufferStatus)                   /* 274 */ \
  OP(Clear)                                    /* 275 */ \
  OP(ClearBufferfi)                            /* 276 */ \
  OP(ClearBufferfvImmediate)                   /* 277 */ \
  OP(ClearBufferivImmediate)                   /* 278 */ \
  OP(ClearBufferuivImmediate)                  /* 279 */ \
  OP(ClearColor)                               /* 280 */ \
  OP(ClearDepthf)                              /* 281 */ \
  OP(ClearStencil)                             /* 282 */ \
  OP(ClientWaitSync)                           /* 283 */ \
  OP(ColorMask)                                /* 284 */ \
  OP(CompileShader)                            /* 285 */ \
  OP(CompressedTexImage2DBucket)               /* 286 */ \
  OP(CompressedTexImage2D)                     /* 287 */ \
  OP(CompressedTexSubImage2DBucket)            /* 288 */ \
  OP(CompressedTexSubImage2D)                  /* 289 */ \
  OP(CompressedTexImage3DBucket)               /* 290 */ \
  OP(CompressedTexImage3D)                     /* 291 */ \
  OP(CompressedTexSubImage3DBucket)            /* 292 */ \
  OP(CompressedTexSubImage3D)                  /* 293 */ \
  OP(CopyBufferSubData)                        /* 294 */ \
  OP(CopyTexImage2D)                           /* 295 */ \
  OP(CopyTexSubImage2D)                        /* 296 */ \
  OP(CopyTexSubImage3D)                        /* 297 */ \
  OP(CreateProgram)                            /* 298 */ \
  OP(CreateShader)                             /* 299 */ \
  OP(CullFace)                                 /* 300 */ \
  OP(DeleteBuffersImmediate)                   /* 301 */ \
  OP(DeleteFramebuffersImmediate)              /* 302 */ \
  OP(DeleteProgram)                            /* 303 */ \
  OP(DeleteRenderbuffersImmediate)             /* 304 */ \
  OP(DeleteSamplersImmediate)                  /* 305 */ \
  OP(DeleteSync)                               /* 306 */ \
  OP(DeleteShader)                             /* 307 */ \
  OP(DeleteTexturesImmediate)                  /* 308 */ \
  OP(DeleteTransformFeedbacksImmediate)        /* 309 */ \
  OP(DepthFunc)                                /* 310 */ \
  OP(DepthMask)                                /* 311 */ \
  OP(DepthRangef)                              /* 312 */ \
  OP(DetachShader)                             /* 313 */ \
  OP(Disable)                                  /* 314 */ \
  OP(DisableVertexAttribArray)                 /* 315 */ \
  OP(DrawArrays)                               /* 316 */ \
  OP(DrawElements)                             /* 317 */ \
  OP(Enable)                                   /* 318 */ \
  OP(EnableVertexAttribArray)                  /* 319 */ \
  OP(FenceSync)                                /* 320 */ \
  OP(Finish)                                   /* 321 */ \
  OP(Flush)                                    /* 322 */ \
  OP(FramebufferRenderbuffer)                  /* 323 */ \
  OP(FramebufferTexture2D)                     /* 324 */ \
  OP(FramebufferTextureLayer)                  /* 325 */ \
  OP(FrontFace)                                /* 326 */ \
  OP(GenBuffersImmediate)                      /* 327 */ \
  OP(GenerateMipmap)                           /* 328 */ \
  OP(GenFramebuffersImmediate)                 /* 329 */ \
  OP(GenRenderbuffersImmediate)                /* 330 */ \
  OP(GenSamplersImmediate)                     /* 331 */ \
  OP(GenTexturesImmediate)                     /* 332 */ \
  OP(GenTransformFeedbacksImmediate)           /* 333 */ \
  OP(GetActiveAttrib)                          /* 334 */ \
  OP(GetActiveUniform)                         /* 335 */ \
  OP(GetActiveUniformBlockiv)                  /* 336 */ \
  OP(GetActiveUniformBlockName)                /* 337 */ \
  OP(GetActiveUniformsiv)                      /* 338 */ \
  OP(GetAttachedShaders)                       /* 339 */ \
  OP(GetAttribLocation)                        /* 340 */ \
  OP(GetBooleanv)                              /* 341 */ \
  OP(GetBufferParameteri64v)                   /* 342 */ \
  OP(GetBufferParameteriv)                     /* 343 */ \
  OP(GetError)                                 /* 344 */ \
  OP(GetFloatv)                                /* 345 */ \
  OP(GetFragDataLocation)                      /* 346 */ \
  OP(GetFramebufferAttachmentParameteriv)      /* 347 */ \
  OP(GetInteger64v)                            /* 348 */ \
  OP(GetIntegeri_v)                            /* 349 */ \
  OP(GetInteger64i_v)                          /* 350 */ \
  OP(GetIntegerv)                              /* 351 */ \
  OP(GetInternalformativ)                      /* 352 */ \
  OP(GetProgramiv)                             /* 353 */ \
  OP(GetProgramInfoLog)                        /* 354 */ \
  OP(GetRenderbufferParameteriv)               /* 355 */ \
  OP(GetSamplerParameterfv)                    /* 356 */ \
  OP(GetSamplerParameteriv)                    /* 357 */ \
  OP(GetShaderiv)                              /* 358 */ \
  OP(GetShaderInfoLog)                         /* 359 */ \
  OP(GetShaderPrecisionFormat)                 /* 360 */ \
  OP(GetShaderSource)                          /* 361 */ \
  OP(GetString)                                /* 362 */ \
  OP(GetSynciv)                                /* 363 */ \
  OP(GetTexParameterfv)                        /* 364 */ \
  OP(GetTexParameteriv)                        /* 365 */ \
  OP(GetTransformFeedbackVarying)              /* 366 */ \
  OP(GetUniformBlockIndex)                     /* 367 */ \
  OP(GetUniformfv)                             /* 368 */ \
  OP(GetUniformiv)                             /* 369 */ \
  OP(GetUniformuiv)                            /* 370 */ \
  OP(GetUniformIndices)                        /* 371 */ \
  OP(GetUniformLocation)                       /* 372 */ \
  OP(GetVertexAttribfv)                        /* 373 */ \
  OP(GetVertexAttribiv)                        /* 374 */ \
  OP(GetVertexAttribIiv)                       /* 375 */ \
  OP(GetVertexAttribIuiv)                      /* 376 */ \
  OP(GetVertexAttribPointerv)                  /* 377 */ \
  OP(Hint)                                     /* 378 */ \
  OP(InvalidateFramebufferImmediate)           /* 379 */ \
  OP(InvalidateSubFramebufferImmediate)        /* 380 */ \
  OP(IsBuffer)                                 /* 381 */ \
  OP(IsEnabled)                                /* 382 */ \
  OP(IsFramebuffer)                            /* 383 */ \
  OP(IsProgram)                                /* 384 */ \
  OP(IsRenderbuffer)                           /* 385 */ \
  OP(IsSampler)                                /* 386 */ \
  OP(IsShader)                                 /* 387 */ \
  OP(IsSync)                                   /* 388 */ \
  OP(IsTexture)                                /* 389 */ \
  OP(IsTransformFeedback)                      /* 390 */ \
  OP(LineWidth)                                /* 391 */ \
  OP(LinkProgram)                              /* 392 */ \
  OP(PauseTransformFeedback)                   /* 393 */ \
  OP(PixelStorei)                              /* 394 */ \
  OP(PolygonOffset)                            /* 395 */ \
  OP(ReadBuffer)                               /* 396 */ \
  OP(ReadPixels)                               /* 397 */ \
  OP(ReleaseShaderCompiler)                    /* 398 */ \
  OP(RenderbufferStorage)                      /* 399 */ \
  OP(ResumeTransformFeedback)                  /* 400 */ \
  OP(SampleCoverage)                           /* 401 */ \
  OP(SamplerParameterf)                        /* 402 */ \
  OP(SamplerParameterfvImmediate)              /* 403 */ \
  OP(SamplerParameteri)                        /* 404 */ \
  OP(SamplerParameterivImmediate)              /* 405 */ \
  OP(Scissor)                                  /* 406 */ \
  OP(ShaderBinary)                             /* 407 */ \
  OP(ShaderSourceBucket)                       /* 408 */ \
  OP(StencilFunc)                              /* 409 */ \
  OP(StencilFuncSeparate)                      /* 410 */ \
  OP(StencilMask)                              /* 411 */ \
  OP(StencilMaskSeparate)                      /* 412 */ \
  OP(StencilOp)                                /* 413 */ \
  OP(StencilOpSeparate)                        /* 414 */ \
  OP(TexImage2D)                               /* 415 */ \
  OP(TexImage3D)                               /* 416 */ \
  OP(TexParameterf)                            /* 417 */ \
  OP(TexParameterfvImmediate)                  /* 418 */ \
  OP(TexParameteri)                            /* 419 */ \
  OP(TexParameterivImmediate)                  /* 420 */ \
  OP(TexStorage3D)                             /* 421 */ \
  OP(TexSubImage2D)                            /* 422 */ \
  OP(TexSubImage3D)                            /* 423 */ \
  OP(TransformFeedbackVaryingsBucket)          /* 424 */ \
  OP(Uniform1f)                                /* 425 */ \
  OP(Uniform1fvImmediate)                      /* 426 */ \
  OP(Uniform1i)                                /* 427 */ \
  OP(Uniform1ivImmediate)                      /* 428 */ \
  OP(Uniform1ui)                               /* 429 */ \
  OP(Uniform1uivImmediate)                     /* 430 */ \
  OP(Uniform2f)                                /* 431 */ \
  OP(Uniform2fvImmediate)                      /* 432 */ \
  OP(Uniform2i)                                /* 433 */ \
  OP(Uniform2ivImmediate)                      /* 434 */ \
  OP(Uniform2ui)                               /* 435 */ \
  OP(Uniform2uivImmediate)                     /* 436 */ \
  OP(Uniform3f)                                /* 437 */ \
  OP(Uniform3fvImmediate)                      /* 438 */ \
  OP(Uniform3i)                                /* 439 */ \
  OP(Uniform3ivImmediate)                      /* 440 */ \
  OP(Uniform3ui)                               /* 441 */ \
  OP(Uniform3uivImmediate)                     /* 442 */ \
  OP(Uniform4f)                                /* 443 */ \
  OP(Uniform4fvImmediate)                      /* 444 */ \
  OP(Uniform4i)                                /* 445 */ \
  OP(Uniform4ivImmediate)                      /* 446 */ \
  OP(Uniform4ui)                               /* 447 */ \
  OP(Uniform4uivImmediate)                     /* 448 */ \
  OP(UniformBlockBinding)                      /* 449 */ \
  OP(UniformMatrix2fvImmediate)                /* 450 */ \
  OP(UniformMatrix2x3fvImmediate)              /* 451 */ \
  OP(UniformMatrix2x4fvImmediate)              /* 452 */ \
  OP(UniformMatrix3fvImmediate)                /* 453 */ \
  OP(UniformMatrix3x2fvImmediate)              /* 454 */ \
  OP(UniformMatrix3x4fvImmediate)              /* 455 */ \
  OP(UniformMatrix4fvImmediate)                /* 456 */ \
  OP(UniformMatrix4x2fvImmediate)              /* 457 */ \
  OP(UniformMatrix4x3fvImmediate)              /* 458 */ \
  OP(UseProgram)                               /* 459 */ \
  OP(ValidateProgram)                          /* 460 */ \
  OP(VertexAttrib1f)                           /* 461 */ \
  OP(VertexAttrib1fvImmediate)                 /* 462 */ \
  OP(VertexAttrib2f)                           /* 463 */ \
  OP(VertexAttrib2fvImmediate)                 /* 464 */ \
  OP(VertexAttrib3f)                           /* 465 */ \
  OP(VertexAttrib3fvImmediate)                 /* 466 */ \
  OP(VertexAttrib4f)                           /* 467 */ \
  OP(VertexAttrib4fvImmediate)                 /* 468 */ \
  OP(VertexAttribI4i)                          /* 469 */ \
  OP(VertexAttribI4ivImmediate)                /* 470 */ \
  OP(VertexAttribI4ui)                         /* 471 */ \
  OP(VertexAttribI4uivImmediate)               /* 472 */ \
  OP(VertexAttribIPointer)                     /* 473 */ \
  OP(VertexAttribPointer)                      /* 474 */ \
  OP(Viewport)                                 /* 475 */ \
  OP(WaitSync)                                 /* 476 */ \
  OP(BlitFramebufferCHROMIUM)                  /* 477 */ \
  OP(RenderbufferStorageMultisampleCHROMIUM)   /* 478 */ \
  OP(RenderbufferStorageMultisampleEXT)        /* 479 */ \
  OP(FramebufferTexture2DMultisampleEXT)       /* 480 */ \
  OP(TexStorage2DEXT)                          /* 481 */ \
  OP(GenQueriesEXTImmediate)                   /* 482 */ \
  OP(DeleteQueriesEXTImmediate)                /* 483 */ \
  OP(QueryCounterEXT)                          /* 484 */ \
  OP(BeginQueryEXT)                            /* 485 */ \
  OP(BeginTransformFeedback)                   /* 486 */ \
  OP(EndQueryEXT)                              /* 487 */ \
  OP(EndTransformFeedback)                     /* 488 */ \
  OP(SetDisjointValueSyncCHROMIUM)             /* 489 */ \
  OP(InsertEventMarkerEXT)                     /* 490 */ \
  OP(PushGroupMarkerEXT)                       /* 491 */ \
  OP(PopGroupMarkerEXT)                        /* 492 */ \
  OP(GenVertexArraysOESImmediate)              /* 493 */ \
  OP(DeleteVertexArraysOESImmediate)           /* 494 */ \
  OP(IsVertexArrayOES)                         /* 495 */ \
  OP(BindVertexArrayOES)                       /* 496 */ \
  OP(SwapBuffers)                              /* 497 */ \
  OP(GetMaxValueInBufferCHROMIUM)              /* 498 */ \
  OP(EnableFeatureCHROMIUM)                    /* 499 */ \
  OP(MapBufferRange)                           /* 500 */ \
  OP(UnmapBuffer)                              /* 501 */ \
  OP(ResizeCHROMIUM)                           /* 502 */ \
  OP(GetRequestableExtensionsCHROMIUM)         /* 503 */ \
  OP(RequestExtensionCHROMIUM)                 /* 504 */ \
  OP(GetProgramInfoCHROMIUM)                   /* 505 */ \
  OP(GetUniformBlocksCHROMIUM)                 /* 506 */ \
  OP(GetTransformFeedbackVaryingsCHROMIUM)     /* 507 */ \
  OP(GetUniformsES3CHROMIUM)                   /* 508 */ \
  OP(GetTranslatedShaderSourceANGLE)           /* 509 */ \
  OP(PostSubBufferCHROMIUM)                    /* 510 */ \
  OP(TexImageIOSurface2DCHROMIUM)              /* 511 */ \
  OP(CopyTextureCHROMIUM)                      /* 512 */ \
  OP(CopySubTextureCHROMIUM)                   /* 513 */ \
  OP(CompressedCopyTextureCHROMIUM)            /* 514 */ \
  OP(DrawArraysInstancedANGLE)                 /* 515 */ \
  OP(DrawElementsInstancedANGLE)               /* 516 */ \
  OP(VertexAttribDivisorANGLE)                 /* 517 */ \
  OP(GenMailboxCHROMIUM)                       /* 518 */ \
  OP(ProduceTextureCHROMIUMImmediate)          /* 519 */ \
  OP(ProduceTextureDirectCHROMIUMImmediate)    /* 520 */ \
  OP(ConsumeTextureCHROMIUMImmediate)          /* 521 */ \
  OP(CreateAndConsumeTextureCHROMIUMImmediate) /* 522 */ \
  OP(BindUniformLocationCHROMIUMBucket)        /* 523 */ \
  OP(GenValuebuffersCHROMIUMImmediate)         /* 524 */ \
  OP(DeleteValuebuffersCHROMIUMImmediate)      /* 525 */ \
  OP(IsValuebufferCHROMIUM)                    /* 526 */ \
  OP(BindValuebufferCHROMIUM)                  /* 527 */ \
  OP(SubscribeValueCHROMIUM)                   /* 528 */ \
  OP(PopulateSubscribedValuesCHROMIUM)         /* 529 */ \
  OP(UniformValuebufferCHROMIUM)               /* 530 */ \
  OP(BindTexImage2DCHROMIUM)                   /* 531 */ \
  OP(ReleaseTexImage2DCHROMIUM)                /* 532 */ \
  OP(TraceBeginCHROMIUM)                       /* 533 */ \
  OP(TraceEndCHROMIUM)                         /* 534 */ \
  OP(AsyncTexSubImage2DCHROMIUM)               /* 535 */ \
  OP(AsyncTexImage2DCHROMIUM)                  /* 536 */ \
  OP(WaitAsyncTexImage2DCHROMIUM)              /* 537 */ \
  OP(WaitAllAsyncTexImage2DCHROMIUM)           /* 538 */ \
  OP(DiscardFramebufferEXTImmediate)           /* 539 */ \
  OP(LoseContextCHROMIUM)                      /* 540 */ \
  OP(InsertSyncPointCHROMIUM)                  /* 541 */ \
  OP(WaitSyncPointCHROMIUM)                    /* 542 */ \
  OP(DrawBuffersEXTImmediate)                  /* 543 */ \
  OP(DiscardBackbufferCHROMIUM)                /* 544 */ \
  OP(ScheduleOverlayPlaneCHROMIUM)             /* 545 */ \
  OP(SwapInterval)                             /* 546 */ \
  OP(FlushDriverCachesCHROMIUM)                /* 547 */ \
  OP(MatrixLoadfCHROMIUMImmediate)             /* 548 */ \
  OP(MatrixLoadIdentityCHROMIUM)               /* 549 */ \
  OP(GenPathsCHROMIUM)                         /* 550 */ \
  OP(DeletePathsCHROMIUM)                      /* 551 */ \
  OP(IsPathCHROMIUM)                           /* 552 */ \
  OP(PathCommandsCHROMIUM)                     /* 553 */ \
  OP(PathParameterfCHROMIUM)                   /* 554 */ \
  OP(PathParameteriCHROMIUM)                   /* 555 */ \
  OP(PathStencilFuncCHROMIUM)                  /* 556 */ \
  OP(StencilFillPathCHROMIUM)                  /* 557 */ \
  OP(StencilStrokePathCHROMIUM)                /* 558 */ \
  OP(CoverFillPathCHROMIUM)                    /* 559 */ \
  OP(CoverStrokePathCHROMIUM)                  /* 560 */ \
  OP(StencilThenCoverFillPathCHROMIUM)         /* 561 */ \
  OP(StencilThenCoverStrokePathCHROMIUM)       /* 562 */ \
  OP(BlendBarrierKHR)                          /* 563 */

enum CommandId {
  kStartPoint = cmd::kLastCommonId,  // All GLES2 commands start after this.
#define GLES2_CMD_OP(name) k##name,
  GLES2_COMMAND_LIST(GLES2_CMD_OP)
#undef GLES2_CMD_OP
      kNumCommands
};

#endif  // GPU_COMMAND_BUFFER_COMMON_GLES2_CMD_IDS_AUTOGEN_H_
