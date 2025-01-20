# confluent_kafka : Kafka 관리 작업 라이브러리리
from confluent_kafka.admin import AdminClient


# Kafka AdminClient 생성
admin_client = AdminClient({
    'bootstrap.servers': 'localhost:9092'
})

# 삭제할 Consumer Group
group_to_delete = 'group2'

# Consumer Group 삭제
try:
    admin_client.delete_consumer_groups([group_to_delete])
    print(f"Consumer Group '{group_to_delete}' has been deleted.")
except Exception as e:
    print(f"Failed to delete Consumer Group '{group_to_delete}': {e}")