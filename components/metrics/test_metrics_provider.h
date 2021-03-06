// Copyright 2015 The Chromium Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file.

#ifndef COMPONENTS_METRICS_TEST_METRICS_PROVIDER_H_
#define COMPONENTS_METRICS_TEST_METRICS_PROVIDER_H_

#include "base/macros.h"
#include "components/metrics/metrics_provider.h"

namespace metrics {

// A simple implementation of MetricsProvider that checks that its providing
// functions are called, for use in tests.
class TestMetricsProvider : public MetricsProvider {
 public:
  TestMetricsProvider()
      : has_initial_stability_metrics_(false),
        provide_initial_stability_metrics_called_(false),
        provide_stability_metrics_called_(false) {}

  // MetricsProvider:
  bool HasInitialStabilityMetrics() override;
  void ProvideInitialStabilityMetrics(
      SystemProfileProto* system_profile_proto) override;
  void ProvideStabilityMetrics(
      SystemProfileProto* system_profile_proto) override;

  void set_has_initial_stability_metrics(bool has_initial_stability_metrics) {
    has_initial_stability_metrics_ = has_initial_stability_metrics;
  }
  bool provide_initial_stability_metrics_called() const {
    return provide_initial_stability_metrics_called_;
  }
  bool provide_stability_metrics_called() const {
    return provide_stability_metrics_called_;
  }

 private:
  bool has_initial_stability_metrics_;
  bool provide_initial_stability_metrics_called_;
  bool provide_stability_metrics_called_;

  DISALLOW_COPY_AND_ASSIGN(TestMetricsProvider);
};

}  // namespace metrics

#endif  // COMPONENTS_METRICS_TEST_METRICS_PROVIDER_H_
