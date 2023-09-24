/*
    Copyright 2023 Munseong Jeong <munseong.jeong@daejin.ac.kr>

Licensed under the Apache License, Version 2.0 (the "License");
you may not use this file except in compliance with the License.
You may obtain a copy of the License at
    http://www.apache.org/licenses/LICENSE-2.0
Unless required by applicable law or agreed to in writing, software
distributed under the License is distributed on an "AS IS" BASIS,
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
See the License for the specific language governing permissions and
limitations under the License.
*/

#include <iostream>
#include <string>
#include <unordered_map>

// Simple class to mimic a database
class SimpleDb {
 public:
  void set_data(const std::string& key,
                const std::string& value) { data_[key] = value; }
  std::string get_data(const std::string& key) const {
    return data_.find(key) == data_.end() ? std::string() : data_.at(key);
  }

 private:
  std::unordered_map<std::string, std::string> data_;
};

class DataFetcher {
 public:
  explicit DataFetcher(const SimpleDb& db) : db_(db) {}

  // Fetch data (Using Cache)
  std::string fetch_data(const std::string& key) const {
    // Check if the data exists in the cache
    // If cache miss occurs, fetch the data from DB and store in the cache
    // NOTICE: Only the data members declared with mutable can be modified in
    //         const member functions
    if (cache_.find(key) == cache_.end())
      cache_[key] = db_.get_data(key);
    return cache_[key];
  }

 private:
  const SimpleDb& db_;
  mutable std::unordered_map<std::string, std::string> cache_;
};

int main() {
  SimpleDb db;
  db.set_data("user_1", "Alice");
  db.set_data("user_2", "Bob");

  DataFetcher fetcher(db);

  // Cache miss, fetches from DB
  std::cout << fetcher.fetch_data("user_1") << std::endl;
  // Cache hit, fetches from cache
  std::cout << fetcher.fetch_data("user_1") << std::endl;
  // Cache hit, fetches from cache
  std::cout << fetcher.fetch_data("user_1") << std::endl;

  // Cache miss, fetches from DB
  std::cout << fetcher.fetch_data("user_2") << std::endl;
  // Cache hit, fetches from cache
  std::cout << fetcher.fetch_data("user_2") << std::endl;
  // Cache hit, fetches from cache
  std::cout << fetcher.fetch_data("user_2") << std::endl;

  return 0;
}

