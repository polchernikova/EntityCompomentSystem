#pragma once

#include <array>
#include <list>

#include "constants.h"
#include "types.h"

class EntityManager {
 public:
  EntityManager();

  Entity CreateEntity();
  void DestroyEntity(Entity entity);

  void SetSignature(Entity entity, Signature signature);
  Signature GetSignature(Entity entity);

 private:
  std::list<Entity> available_entities_;

  std::array<Signature, constants::kMaxEntities> signatures_{};
  uint32_t living_entity_count_;
};
