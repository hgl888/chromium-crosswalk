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
  OP(GetBufferParameteriv)                     /* 342 */ \
  OP(GetError)                                 /* 343 */ \
  OP(GetFloatv)                                /* 344 */ \
  OP(GetFragDataLocation)                      /* 345 */ \
  OP(GetFramebufferAttachmentParameteriv)      /* 346 */ \
  OP(GetInteger64v)                            /* 347 */ \
  OP(GetIntegeri_v)                            /* 348 */ \
  OP(GetInteger64i_v)                          /* 349 */ \
  OP(GetIntegerv)                              /* 350 */ \
  OP(GetInternalformativ)                      /* 351 */ \
  OP(GetProgramiv)                             /* 352 */ \
  OP(GetProgramInfoLog)                        /* 353 */ \
  OP(GetRenderbufferParameteriv)               /* 354 */ \
  OP(GetSamplerParameterfv)                    /* 355 */ \
  OP(GetSamplerParameteriv)                    /* 356 */ \
  OP(GetShaderiv)                              /* 357 */ \
  OP(GetShaderInfoLog)                         /* 358 */ \
  OP(GetShaderPrecisionFormat)                 /* 359 */ \
  OP(GetShaderSource)                          /* 360 */ \
  OP(GetString)                                /* 361 */ \
  OP(GetSynciv)                                /* 362 */ \
  OP(GetTexParameterfv)                        /* 363 */ \
  OP(GetTexParameteriv)                        /* 364 */ \
  OP(GetTransformFeedbackVarying)              /* 365 */ \
  OP(GetUniformBlockIndex)                     /* 366 */ \
  OP(GetUniformfv)                             /* 367 */ \
  OP(GetUniformiv)                             /* 368 */ \
  OP(GetUniformuiv)                            /* 369 */ \
  OP(GetUniformIndices)                        /* 370 */ \
  OP(GetUniformLocation)                       /* 371 */ \
  OP(GetVertexAttribfv)                        /* 372 */ \
  OP(GetVertexAttribiv)                        /* 373 */ \
  OP(GetVertexAttribIiv)                       /* 374 */ \
  OP(GetVertexAttribIuiv)                      /* 375 */ \
  OP(GetVertexAttribPointerv)                  /* 376 */ \
  OP(Hint)                                     /* 377 */ \
  OP(InvalidateFramebufferImmediate)           /* 378 */ \
  OP(InvalidateSubFramebufferImmediate)        /* 379 */ \
  OP(IsBuffer)                                 /* 380 */ \
  OP(IsEnabled)                                /* 381 */ \
  OP(IsFramebuffer)                            /* 382 */ \
  OP(IsProgram)                                /* 383 */ \
  OP(IsRenderbuffer)                           /* 384 */ \
  OP(IsSampler)                                /* 385 */ \
  OP(IsShader)                                 /* 386 */ \
  OP(IsSync)                                   /* 387 */ \
  OP(IsTexture)                                /* 388 */ \
  OP(IsTransformFeedback)                      /* 389 */ \
  OP(LineWidth)                                /* 390 */ \
  OP(LinkProgram)                              /* 391 */ \
  OP(PauseTransformFeedback)                   /* 392 */ \
  OP(PixelStorei)                              /* 393 */ \
  OP(PolygonOffset)                            /* 394 */ \
  OP(ReadBuffer)                               /* 395 */ \
  OP(ReadPixels)                               /* 396 */ \
  OP(ReleaseShaderCompiler)                    /* 397 */ \
  OP(RenderbufferStorage)                      /* 398 */ \
  OP(ResumeTransformFeedback)                  /* 399 */ \
  OP(SampleCoverage)                           /* 400 */ \
  OP(SamplerParameterf)                        /* 401 */ \
  OP(SamplerParameterfvImmediate)              /* 402 */ \
  OP(SamplerParameteri)                        /* 403 */ \
  OP(SamplerParameterivImmediate)              /* 404 */ \
  OP(Scissor)                                  /* 405 */ \
  OP(ShaderBinary)                             /* 406 */ \
  OP(ShaderSourceBucket)                       /* 407 */ \
  OP(StencilFunc)                              /* 408 */ \
  OP(StencilFuncSeparate)                      /* 409 */ \
  OP(StencilMask)                              /* 410 */ \
  OP(StencilMaskSeparate)                      /* 411 */ \
  OP(StencilOp)                                /* 412 */ \
  OP(StencilOpSeparate)                        /* 413 */ \
  OP(TexImage2D)                               /* 414 */ \
  OP(TexImage3D)                               /* 415 */ \
  OP(TexParameterf)                            /* 416 */ \
  OP(TexParameterfvImmediate)                  /* 417 */ \
  OP(TexParameteri)                            /* 418 */ \
  OP(TexParameterivImmediate)                  /* 419 */ \
  OP(TexStorage3D)                             /* 420 */ \
  OP(TexSubImage2D)                            /* 421 */ \
  OP(TexSubImage3D)                            /* 422 */ \
  OP(TransformFeedbackVaryingsBucket)          /* 423 */ \
  OP(Uniform1f)                                /* 424 */ \
  OP(Uniform1fvImmediate)                      /* 425 */ \
  OP(Uniform1i)                                /* 426 */ \
  OP(Uniform1ivImmediate)                      /* 427 */ \
  OP(Uniform1ui)                               /* 428 */ \
  OP(Uniform1uivImmediate)                     /* 429 */ \
  OP(Uniform2f)                                /* 430 */ \
  OP(Uniform2fvImmediate)                      /* 431 */ \
  OP(Uniform2i)                                /* 432 */ \
  OP(Uniform2ivImmediate)                      /* 433 */ \
  OP(Uniform2ui)                               /* 434 */ \
  OP(Uniform2uivImmediate)                     /* 435 */ \
  OP(Uniform3f)                                /* 436 */ \
  OP(Uniform3fvImmediate)                      /* 437 */ \
  OP(Uniform3i)                                /* 438 */ \
  OP(Uniform3ivImmediate)                      /* 439 */ \
  OP(Uniform3ui)                               /* 440 */ \
  OP(Uniform3uivImmediate)                     /* 441 */ \
  OP(Uniform4f)                                /* 442 */ \
  OP(Uniform4fvImmediate)                      /* 443 */ \
  OP(Uniform4i)                                /* 444 */ \
  OP(Uniform4ivImmediate)                      /* 445 */ \
  OP(Uniform4ui)                               /* 446 */ \
  OP(Uniform4uivImmediate)                     /* 447 */ \
  OP(UniformBlockBinding)                      /* 448 */ \
  OP(UniformMatrix2fvImmediate)                /* 449 */ \
  OP(UniformMatrix2x3fvImmediate)              /* 450 */ \
  OP(UniformMatrix2x4fvImmediate)              /* 451 */ \
  OP(UniformMatrix3fvImmediate)                /* 452 */ \
  OP(UniformMatrix3x2fvImmediate)              /* 453 */ \
  OP(UniformMatrix3x4fvImmediate)              /* 454 */ \
  OP(UniformMatrix4fvImmediate)                /* 455 */ \
  OP(UniformMatrix4x2fvImmediate)              /* 456 */ \
  OP(UniformMatrix4x3fvImmediate)              /* 457 */ \
  OP(UseProgram)                               /* 458 */ \
  OP(ValidateProgram)                          /* 459 */ \
  OP(VertexAttrib1f)                           /* 460 */ \
  OP(VertexAttrib1fvImmediate)                 /* 461 */ \
  OP(VertexAttrib2f)                           /* 462 */ \
  OP(VertexAttrib2fvImmediate)                 /* 463 */ \
  OP(VertexAttrib3f)                           /* 464 */ \
  OP(VertexAttrib3fvImmediate)                 /* 465 */ \
  OP(VertexAttrib4f)                           /* 466 */ \
  OP(VertexAttrib4fvImmediate)                 /* 467 */ \
  OP(VertexAttribI4i)                          /* 468 */ \
  OP(VertexAttribI4ivImmediate)                /* 469 */ \
  OP(VertexAttribI4ui)                         /* 470 */ \
  OP(VertexAttribI4uivImmediate)               /* 471 */ \
  OP(VertexAttribIPointer)                     /* 472 */ \
  OP(VertexAttribPointer)                      /* 473 */ \
  OP(Viewport)                                 /* 474 */ \
  OP(WaitSync)                                 /* 475 */ \
  OP(BlitFramebufferCHROMIUM)                  /* 476 */ \
  OP(RenderbufferStorageMultisampleCHROMIUM)   /* 477 */ \
  OP(RenderbufferStorageMultisampleEXT)        /* 478 */ \
  OP(FramebufferTexture2DMultisampleEXT)       /* 479 */ \
  OP(TexStorage2DEXT)                          /* 480 */ \
  OP(GenQueriesEXTImmediate)                   /* 481 */ \
  OP(DeleteQueriesEXTImmediate)                /* 482 */ \
  OP(BeginQueryEXT)                            /* 483 */ \
  OP(BeginTransformFeedback)                   /* 484 */ \
  OP(EndQueryEXT)                              /* 485 */ \
  OP(EndTransformFeedback)                     /* 486 */ \
  OP(InsertEventMarkerEXT)                     /* 487 */ \
  OP(PushGroupMarkerEXT)                       /* 488 */ \
  OP(PopGroupMarkerEXT)                        /* 489 */ \
  OP(GenVertexArraysOESImmediate)              /* 490 */ \
  OP(DeleteVertexArraysOESImmediate)           /* 491 */ \
  OP(IsVertexArrayOES)                         /* 492 */ \
  OP(BindVertexArrayOES)                       /* 493 */ \
  OP(SwapBuffers)                              /* 494 */ \
  OP(GetMaxValueInBufferCHROMIUM)              /* 495 */ \
  OP(EnableFeatureCHROMIUM)                    /* 496 */ \
  OP(MapBufferRange)                           /* 497 */ \
  OP(UnmapBuffer)                              /* 498 */ \
  OP(ResizeCHROMIUM)                           /* 499 */ \
  OP(GetRequestableExtensionsCHROMIUM)         /* 500 */ \
  OP(RequestExtensionCHROMIUM)                 /* 501 */ \
  OP(GetProgramInfoCHROMIUM)                   /* 502 */ \
  OP(GetUniformBlocksCHROMIUM)                 /* 503 */ \
  OP(GetTransformFeedbackVaryingsCHROMIUM)     /* 504 */ \
  OP(GetUniformsES3CHROMIUM)                   /* 505 */ \
  OP(GetTranslatedShaderSourceANGLE)           /* 506 */ \
  OP(PostSubBufferCHROMIUM)                    /* 507 */ \
  OP(TexImageIOSurface2DCHROMIUM)              /* 508 */ \
  OP(CopyTextureCHROMIUM)                      /* 509 */ \
  OP(CopySubTextureCHROMIUM)                   /* 510 */ \
  OP(CompressedCopyTextureCHROMIUM)            /* 511 */ \
  OP(DrawArraysInstancedANGLE)                 /* 512 */ \
  OP(DrawElementsInstancedANGLE)               /* 513 */ \
  OP(VertexAttribDivisorANGLE)                 /* 514 */ \
  OP(GenMailboxCHROMIUM)                       /* 515 */ \
  OP(ProduceTextureCHROMIUMImmediate)          /* 516 */ \
  OP(ProduceTextureDirectCHROMIUMImmediate)    /* 517 */ \
  OP(ConsumeTextureCHROMIUMImmediate)          /* 518 */ \
  OP(CreateAndConsumeTextureCHROMIUMImmediate) /* 519 */ \
  OP(BindUniformLocationCHROMIUMBucket)        /* 520 */ \
  OP(GenValuebuffersCHROMIUMImmediate)         /* 521 */ \
  OP(DeleteValuebuffersCHROMIUMImmediate)      /* 522 */ \
  OP(IsValuebufferCHROMIUM)                    /* 523 */ \
  OP(BindValuebufferCHROMIUM)                  /* 524 */ \
  OP(SubscribeValueCHROMIUM)                   /* 525 */ \
  OP(PopulateSubscribedValuesCHROMIUM)         /* 526 */ \
  OP(UniformValuebufferCHROMIUM)               /* 527 */ \
  OP(BindTexImage2DCHROMIUM)                   /* 528 */ \
  OP(ReleaseTexImage2DCHROMIUM)                /* 529 */ \
  OP(TraceBeginCHROMIUM)                       /* 530 */ \
  OP(TraceEndCHROMIUM)                         /* 531 */ \
  OP(AsyncTexSubImage2DCHROMIUM)               /* 532 */ \
  OP(AsyncTexImage2DCHROMIUM)                  /* 533 */ \
  OP(WaitAsyncTexImage2DCHROMIUM)              /* 534 */ \
  OP(WaitAllAsyncTexImage2DCHROMIUM)           /* 535 */ \
  OP(DiscardFramebufferEXTImmediate)           /* 536 */ \
  OP(LoseContextCHROMIUM)                      /* 537 */ \
  OP(InsertSyncPointCHROMIUM)                  /* 538 */ \
  OP(WaitSyncPointCHROMIUM)                    /* 539 */ \
  OP(DrawBuffersEXTImmediate)                  /* 540 */ \
  OP(DiscardBackbufferCHROMIUM)                /* 541 */ \
  OP(ScheduleOverlayPlaneCHROMIUM)             /* 542 */ \
  OP(SwapInterval)                             /* 543 */ \
  OP(FlushDriverCachesCHROMIUM)                /* 544 */ \
  OP(MatrixLoadfCHROMIUMImmediate)             /* 545 */ \
  OP(MatrixLoadIdentityCHROMIUM)               /* 546 */ \
  OP(GenPathsCHROMIUM)                         /* 547 */ \
  OP(DeletePathsCHROMIUM)                      /* 548 */ \
  OP(IsPathCHROMIUM)                           /* 549 */ \
  OP(PathCommandsCHROMIUM)                     /* 550 */ \
  OP(PathParameterfCHROMIUM)                   /* 551 */ \
  OP(PathParameteriCHROMIUM)                   /* 552 */ \
  OP(PathStencilFuncCHROMIUM)                  /* 553 */ \
  OP(StencilFillPathCHROMIUM)                  /* 554 */ \
  OP(StencilStrokePathCHROMIUM)                /* 555 */ \
  OP(CoverFillPathCHROMIUM)                    /* 556 */ \
  OP(CoverStrokePathCHROMIUM)                  /* 557 */ \
  OP(StencilThenCoverFillPathCHROMIUM)         /* 558 */ \
  OP(StencilThenCoverStrokePathCHROMIUM)       /* 559 */ \
  OP(BlendBarrierKHR)                          /* 560 */

enum CommandId {
  kStartPoint = cmd::kLastCommonId,  // All GLES2 commands start after this.
#define GLES2_CMD_OP(name) k##name,
  GLES2_COMMAND_LIST(GLES2_CMD_OP)
#undef GLES2_CMD_OP
      kNumCommands
};

#endif  // GPU_COMMAND_BUFFER_COMMON_GLES2_CMD_IDS_AUTOGEN_H_
