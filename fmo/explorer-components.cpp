#include "explorer-impl.hpp"
#include "include-opencv.hpp"
#include <algorithm>
#include <fmo/algebra.hpp>
#include <fmo/assert.hpp>

namespace fmo {
    namespace {
        constexpr int int16_max = std::numeric_limits<int16_t>::max();
    }

    void Explorer::Impl::findComponents() {
        // reset
        mComponents.clear();
        FMO_ASSERT(!mLevels.empty(), "no levels");
        int step = mLevels[0].step;

        FMO_ASSERT(mStrips.size() < size_t(int16_max), "too many strips");
        int numStrips = int(mStrips.size());
        // not tested: it is assumed that the strips are sorted by x coordinate

        for (int i = 0; i < numStrips; i++) {
            Strip& me = mStrips[i];

            // create new components for previously untouched strips
            if (me.special == Strip::UNTOUCHED) { mComponents.emplace_back(int16_t(i)); }

            // find next strip
            me.special = Strip::END;
            for (int j = i + 1; j < numStrips; j++) {
                Strip& candidate = mStrips[j];
                int dx = candidate.x - me.x;
                if (dx > step) break;
                int dy = fmo::abs(candidate.y - me.y);
                if (dy < me.halfHeight + candidate.halfHeight) {
                    candidate.special = Strip::TOUCHED;
                    me.special = int16_t(j);
                    break;
                }
            }
        }
    }

    void Explorer::Impl::analyzeComponents() {
        auto& halfHeights = mSortCache;
        for (auto& comp : mComponents) {
            halfHeights.clear();
            int index = comp.first;
            Strip* strip = &mStrips[index];

            while (true) {
                halfHeights.push_back(strip->halfHeight);

                if (strip->special == Strip::END) break;
                index = strip->special;
                strip = &mStrips[index];
            }

            auto mid = begin(halfHeights) + (halfHeights.size() / 2);
            std::nth_element(begin(halfHeights), mid, end(halfHeights));
            comp.last = int16_t(index);
            comp.numStrips = int16_t(halfHeights.size());
            comp.approxHalfHeight = int16_t(*mid);
        }
    }
}
